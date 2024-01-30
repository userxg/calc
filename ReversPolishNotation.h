#pragma once

#ifndef _REVERS_POLISH_NOTATION_
#define _REVERS_POLISH_NOTATION_

#include "DoubleLinkedStack.h"
#include "HashMap.h"
#include <string>

#include "vec2.h"
#include "MathFunctions.h"
#include "FunctionValueation.h"

typedef SDLL<vec2> sdll_vec;
typedef SDLL<std::string> sdll_op;
typedef SDLL<char> sdll_c;

class GetPolishNotation {
private:

	sdll_op opB;
	sdll_op op;
	sdll_vec nums;
	HashMap iF;

public:

	GetPolishNotation() {
		for (int i = 0; i < _FUNCTION_NAME_ARRAY_SIZE_; i++) {
			iF.put(FunctionNames[i], FunctionValue[i], FunctionPointers[i], FunctionLimitPointers[i], FunctionDataType[i], FunctionsNumInputs[i]);
		}
	}

	void printRPN()const {
		std::cout << "\n\n--Revers Polish Notation Start--\n";
		op.print();
		std::cout << '\n';
		nums.print();
		std::cout<< "\n--Revers Polish Notation End--\n\n";
	}

	void rpn(std::string& line) {

		Correction(line);
		std::cout << "The expration: " << line << '\n';

		bool Im = false;

		std::string buf = "";
		int i(0);
		int length_line = line.length();
		while (i < length_line) {
			std::string c(1, line[i]);

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

			while(IsNum(c)){
				if (i >= length_line) {
					break;
				}

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

					buf = "";
					break;
				}

				if (c == "i") {
					i++;
					Im = true;
				}
				else {
					buf += c;
					i++;
				}
			}

			while (!IsNum(c)) {
				std::string c(1, line[i]);

				if (i >= length_line || c == "(" || c == ")" || IsNum(c)) {
					if (!(c == "i" && !IsNum(line[i-1]))) {
						break;
					}
				}

				buf += c;
				i++;

				if (iF.getV(buf)) {
					while (!opB.empty() && iF.getV(buf) <= iF.getV(opB.get())) {
						op.add(opB.pop());
					}
					opB.add(buf);
					buf = "";
				}

			}

		}
		if (IsNum(buf[0]) || line[length_line-1]=='i') {
			if (Im == true) {
				if (buf == "") {
					nums.add(vec2(0, 1));
					op.add("NUM");
				}
				else {
					nums.add(vec2(0, stold(buf)));
					op.add("NUM");
				}
			}
			else {
				nums.add(vec2(stold(buf)));
				op.add("NUM");
			}
		}
		else {
			if (buf != "") {
				op.add(buf);
			}
		}

		while (!opB.empty()) {
			op.add(opB.pop());
		}

		eval();
	}

	void eval() {

		printRPN();
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

				//std::cout << oper << " " << (int)numInp << " " << DataType << '\n';
				if (numInp == 1) {
					
					if (DataType == "vec2") {
						vec2 resNum = ((vec2(*)(vec2))iF.getP(oper))(buf.pop());
						buf.add(resNum);
						//std::cout << resNum << '\n';
					}
				}
				else if (numInp == 2) {
					if (DataType == "vec2") {
						vec2 resNum = ((vec2(*)(vec2,vec2))iF.getP(oper))(buf.pop(), buf.pop());
						buf.add(resNum);
						//std::cout << resNum << '\n';
					}
				}

				op.popH();
			}
		}
		std::cout << "Result: ";
		buf.print();
	}

private:

	void Correction(std::string& line) {
		DeleteSpace(line);
		if (!BracketsCorrectionCheck(line)) {
			std::cout << "Wrong line format: Check Brackets for correction";
			return;
		}
		FixLayers(line);
	}

	void FixLayers(std::string& line) {
		std::string new_line = "";

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
	bool DefOp(const std::string& c) {
		return c == "+" || c == "-" || c == "*" || c == "/";
	}

	bool IsLetter(const std::string& c) {
		return c!="i" && (("a" <= c && c <= "z") || ("A" <= c && c <= "Z"));
	}

	bool IsNum(const std::string& c) {
		return ("0" <= c && c <= "9") || c == "." || c=="i";
	}
	bool IsNum(const char& c) {
		return ('0' <= c && c <= '9') || c == '.';
	}
};
#endif