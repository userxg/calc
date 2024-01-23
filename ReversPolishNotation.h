#pragma once

#ifndef _REVERS_POLISH_NOTATION_
#define _REVERS_POLISH_NOTATION_

#include "DoubleLinkedStack.h"
#include "HashMap.h"

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

	sdll_op op;
	sdll_vec nums;

	HashMap<char> FuncVal;

public:

	GetPolishNotation() {
		for (int i = 0; i < _FUNCTION_NAME_ARRAY_SIZE_; i++) {
			FuncVal.put(FunctionNames[i], FunctionValue[i]);
		}
	}

	void printRPN()const {
		std::cout << "\n\n--Revers Polish Notation Start--\n";
		op.print();
		std::cout << '\n';
		nums.print();
		std::cout<< "\n--Revers Polish Notation End--\n\n";
	}

private:

	void Correction(std::string& line) {
		line = DeleteSpace(line);
		if (!BracketsCorrectionCheck(line)) {
			cout << "Wrong line format";
			return;
		}
	}

	void CalRPN(const std::string& line) {

		std::string buf;
		for (char c : line) {
			std::string ch(1, c);

			if (IsNum(ch)) {
				buf += ch;
			}
		}
	}

	void CalRPN(const std::string& line) {

		std::string buf;
		for (char c : line) {
			std::string ch(1, c);

			if (IsNum(ch)) {
				buf += ch;
			}
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

	bool IsNum(std::string c) {
		return ("0" <= c && c <= "9") || c == ".";
	}
};
#endif