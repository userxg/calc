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

/*

Есть функция на проверку скобок ( '(' и ')' ) и удаление пробелов - BracketsCorrectionCheck(line), DeleteSpace(line) соотв. 

*/

class GetPolishNotation {
private:

	sdll_op opB;
	sdll_op op;
	sdll_vec nums;
	HashMap iF;

public:

	GetPolishNotation() {
		for (int i = 0; i < _FUNCTION_NAME_ARRAY_SIZE_; i++) {
			iF.put(FunctionNames[i], FunctionValue[i], FunctionPointers[i], FunctionLimitPointers[i], FunctionDataType[i]);
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

		bool Im = false;
		bool num = false;
		bool oper = false;

		std::string buf = "";
		int i(0);
		int length_line = line.length();
		while (i < length_line) {
			std::string c(1, line[i]);

			if (c == ")") {

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
						buf = "";
						Im = false;
						break;
					}
					else {
						nums.add(vec2(stold(buf)));
						op.add("NUM");
						buf = "";
						break;
					}

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
				if (i >= length_line) {
					break;
				}

				std::string c(1, line[i]);
				if (IsNum(c)) {
					break;
				}
				if (DefOp(c)) {

					if (buf != "") {
						op.add(buf);
					}

					op.add(c);
					buf = "";
					i++;
					break;
				}

				buf += c;
				i++;
			}

		}
		if (IsNum(buf[0]) || line[length_line-1]=='i') {

			if (Im == true) {
				if (buf == "") {
					nums.add(vec2(0, 1));
					op.add("NUM");
					Im = false;
				}
				else {
					nums.add(vec2(0, stold(buf)));
					op.add("NUM");
					buf = "";
					Im = false;
				}
			}
			else {
				nums.add(vec2(stold(buf)));
				op.add("NUM");
				buf = "";
			}
		}
		else {
			op.add(buf);
		}
	}

private:

	void Correction(std::string& line) {
		line = DeleteSpace(line);
		if (!BracketsCorrectionCheck(line)) {
			std::cout << "Wrong line format";
			return;
		}
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

	std::string DeleteSpace(std::string line) {
		std::string new_line = "";

		for (char c : line) {
			if (c != ' ')
				new_line += c;
		}

		return new_line;
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