#pragma once

#ifndef _REVERS_POLISH_NOTATION_
#define _REVERS_POLISH_NOTATION_

#include "HashMap.h"
#include <string>

#include "vec2.h"
#include "MathFunctions.h"
#include "FunctionValueation.h"
#include "DoubleLinkedStack.h"

typedef SDLL<vec2> sdll_vec;
typedef SDLL<std::string> sdll_op;
typedef SDLL<char> sdll_c;

class calculator {
private:

	sdll_op opB;
	sdll_op op;
	sdll_vec nums;

	HashMap iF;

public:

	calculator() {
		for (int i = 0; i < _FUNCTION_NAME_ARRAY_SIZE_; i++) {
			iF.put(FunctionNames[i], FunctionValue[i], FunctionPointers[i], FunctionLimitPointers[i], FunctionDataType[i], FunctionsNumInputs[i],FunctionsEval[i]);
		}
	}

	vec2 Solve(std::string line) {
		Correction(line);

		const int line_str = line.length();

		std::string MainFunction;
		bool oneFunc = true;
		for (int i = 0; i < line_str; i++) {
			if (line[i] != ';') {
				MainFunction += line[i];
			}
			else {
				oneFunc = false;
				break;
			}
		}

		if (oneFunc) {
			return rpn(MainFunction);
		}

		for (int i = line_str - 1; i >= 0; i--) {
			if (line[i] == ';') {
				SubFunc(line, i);
			}
		}

		return rpn(MainFunction);
	}

private:
	void printRPN()const {
		std::cout << "\n--Revers Polish Notation Start--\n";
		op.print();
		std::cout << '\n';
		nums.print();
		std::cout<< "\n--Revers Polish Notation End--\n";
	}

	void SubFunc(std::string& line, int start) {
		std::string newFunc;
		std::string newFuncName;

		while (++start < line.length()) {
			if (line[start] == '=') {
				break;
			}
			newFuncName += line[start];
		}
		while (++start < line.length() && line[start]!=';') {
			newFunc += line[start];
		}

		if (iF.inmap(newFuncName)) {
			std::cout << "\nRedefining already existing function\n";
			return;
		}

		vec2 Eval = rpn(newFunc);
		iF.put(newFuncName, 0, nullptr, nullptr, "vec2", 0, Eval);
	}


	vec2 rpn(std::string& line) {

		int i(0);
		const int length_line = line.length();
		while (i < length_line) {
			std::string c(1, line[i]);

			if (c == ",") {
				i++;
			}

			if (c == "(") {
				opB.add(c);
				i++;
			}

			if (c == ")") {
				while (!opB.empty() && opB.get() != "(") {
					op.add(opB.pop());
				}
				opB.pop();
				i++;
			}

			if (IsNum(c)) {
				NumberAdd(line, i, length_line);
			}
			else {
				FunctionAdd(line, i, length_line);
			}

		}

		while (!opB.empty()) {
			op.add(opB.pop());
		}

		return eval();
	}

	void FunctionAdd(const std::string& line, int& i, const int& length_line) {

		std::string buf;
		while (i < length_line) {
			std::string c(1, line[i]);

			if (c == "(" || c == ")" || (IsNum(c) && c!="i")) {
				break;
			}
			if (c == "i" && buf == "") {
				break;
			}

			buf += c;
			i++;

			if (iF.getV(buf) && iF.getNInp(buf)) {
				while (!opB.empty() && iF.getV(buf) <= iF.getV(opB.get())) {
					op.add(opB.pop());
				}
				opB.add(buf);
				buf = "";
			}
			else if(iF.getEv(buf).r || iF.getEv(buf).i){
				nums.add(iF.getEv(buf));
				op.add("NUM");
				buf = "";
			}
		}
	}

	void NumberAdd(const std::string& line, int& i,const int& length_line){

		bool Im = false;
		std::string buf;
		while (i< length_line) {
			std::string c(1, line[i]);

			if (!IsNum(c)) {

				if (Im == true) {
					if (buf == "") {
						nums.add(vec2(0, 1));
					}
					else {
						nums.add(vec2(0, stold(buf)));
					}
					op.add("NUM");
					Im = false;
				}
				else {
					nums.add(vec2(stold(buf)));
					op.add("NUM");
				}

				break;
			}

			if (c == "i") {
				Im = true;
			}
			else {
				buf += c;
			}
			i++;
		}
		if (i == length_line ) {
			if (Im == true) {
				if (buf == "") {
					nums.add(vec2(0, 1));
				}
				else {
					nums.add(vec2(0, stold(buf)));
				}
				op.add("NUM");
				Im = false;
			}
			else {
				nums.add(vec2(stold(buf)));
				op.add("NUM");
			}
		}
	}

	vec2 eval() {

		sdll_vec buf;
		while (!op.empty()) {

			std::string oper = op.getH();
			if (oper == "NUM") {
				buf.add(nums.popH());
				op.popH();
			}
			else {
				char numInp = iF.getNInp(op.getH());
				std::string DataType = iF.getDt(op.getH());

				switch (numInp) {

					if (!IsNextNumberHere(buf)) {
						std::cout << "\nOps...\nSomething went wrong\nCheck the correction of equation\n";
						return vec2(-1);
					}

				case 1:
					if (DataType == "vec2") {
						vec2 bufNum = buf.pop();
						DomainCheck(oper, bufNum);

						vec2 resNum = ((vec2(*)(vec2))iF.getP(oper))(bufNum);
						buf.add(resNum);
					}
					else if (DataType == "ld") {
						ld bufNum = buf.pop().r;
						DomainCheck(oper, bufNum);

						vec2 resNum = ((ld(*)(ld))iF.getP(oper))(bufNum);
						buf.add(resNum);
					}
					else if (DataType == "lli") {
						lli bufNum = buf.pop().r;
						DomainCheck(oper, bufNum);

						vec2 resNum = ((lli(*)(lli))iF.getP(oper))(bufNum);
						buf.add(resNum);
					}
					break;
				case 2:
					if (DataType == "vec2") {
						vec2 bufNum = buf.pop();

						vec2 bufNum1 = buf.pop();
						DomainCheck(oper, bufNum);

						vec2 resNum = ((vec2(*)(vec2, vec2))iF.getP(oper))(bufNum1, bufNum);
						buf.add(resNum);
					}
					else if (DataType == "lli") {
						vec2 bufNum = buf.pop();

						vec2 bufNum1 = buf.pop();

						DomainCheck(oper, (lli)bufNum.r,(lli) bufNum1.r);

						vec2 resNum = ((lli(*)(lli, lli))iF.getP(oper))((lli)bufNum.r, (lli)bufNum1.r);
						buf.add(resNum);
					}

				}

				op.popH();
			}
		}

		return buf.pop();
	}

	void Correction(std::string& line) {
		DeleteSpace(line);
		if (!BracketsCorrectionCheck(line)) {
			std::cout << "Wrong line format: Check Brackets for correction";
			return;
		}
		FixLayers(line);
	}

	void FixLayers(std::string& line) {
		std::string new_line;

		if (line[0] == '-' || line[0] == '+') {
			new_line += '0';
		}

		for (int i = 0; i < line.length(); i++) {

			if (line[i] == '(' && (line[i+1]=='+' || line[i+1]=='-')) {
				new_line += '(';
				new_line += '0';
			}
			else {
				new_line += line[i];
			}
		}
		line = new_line;
	}

	bool BracketsCorrectionCheck(const std::string line) {
		sdll_c stack;

		for (char c : line) {

			if (c == '(') {
				stack.add(c);
			}
			else if (c == ')' && stack.pop() == ')') {
				stack.pop();
			}
		}
		return stack.empty();
	}

	void DeleteSpace(std::string& line) {
		std::string new_line = "";

		for (char c : line) {
			if (c != ' ')
				new_line += c;
		}

		line = new_line;
	}

	bool IsNextNumberHere(sdll_vec& buf) {
		if (buf.get() == NULL) {
			return false;
		}
		return true;
	}

	void DomainCheck(const std::string& oper, const vec2& resNum){
		if (iF.getLP(oper)==nullptr) {
			return;
		}
		if (!((bool(*)(vec2))iF.getLP(oper))(resNum)) {
			std::cout << "!ERROR!\nOperator: " << oper <<"\nInput: "<<resNum<< "\nResul: Input is not in function's domain\n";
			throw std::invalid_argument("Input is not in function's domain");
		}
	}
	void DomainCheck(const std::string& oper, const ld& resNum) {
		if (iF.getLP(oper) == nullptr) {
			return;
		}
		if (!((bool(*)(ld))iF.getLP(oper))(resNum)) {
			std::cout << "!ERROR!\nOperator: " << oper << "\nInput: " << resNum << "\nResul: Input is not in function's domain\n";
			throw std::invalid_argument("Input is not in function's domain");
		}
	}
	void DomainCheck(const std::string& oper, const vec2& resNum, const vec2& resNum1) {

		if (!(resNum.i == 0 && resNum1.i == 0) || ((lli)resNum.r!=resNum.r) || ((lli)resNum1.r != resNum1.r)) {
			std::cout << "!ERROR!\nOperator: " << oper << "\nInput: " << resNum << "\nResul: Input is not in function's domain\n";
			throw std::invalid_argument("Input is not in function's domain");
		}

		if (iF.getLP(oper) == nullptr) {
			return;
		}
		if (!((bool(*)(lli,lli))iF.getLP(oper))((lli)resNum.r, (lli)resNum1.r)) {
			std::cout << "!ERROR!\nOperator: " << oper << "\nInput: " << resNum << "\nResul: Input is not in function's domain\n";
			throw std::invalid_argument("Input is not in function's domain");
		}
	}

	bool IsNum(const std::string& c) {
		return ("0" <= c && c <= "9") || c == "." || c=="i";
	}
	bool IsNum(const char& c) {
		return ('0' <= c && c <= '9') || c == '.';
	}
};
#endif