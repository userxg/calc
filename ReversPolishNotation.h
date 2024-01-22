#pragma once

#ifndef _REVERS_POLISH_NOTATION_
#define _REVERS_POLISH_NOTATION_

#include "DoubleLinkedStack.h"
#include "MathFunctions.h"

typedef SDLL<vec2> sdll_vec;
typedef SDLL<string> sdll_str;
typedef SDLL<char> sdll_c;
typedef SDLL<HashMap> Map;

/*

Есть функция на проверку скобок ( '(' и ')' ) и удаление пробелов - BracketsCorrectionCheck(line), DeleteSpace(line) соотв. 

Для получение стоимости (приоритет) каждой функции в виде HashMap используется функция ConnectHash()
Названия функций, а также их веса заранее лежат в "MathFunctions.h"

*/

class GetPolishNotation {
private:
	MathFunctions libMF;

	sdll_str op;
	sdll_vec nums;
	Map vMap;

public:

	GetPolishNotation() {

		for (int i = 0; i < _FUNCTION_NAME_ARRAY_SIZE_; i++) {
			if (libMF.FunctionValue[i]) {

				HashMap node;
				node.Key = libMF.FunctionNames[i];
				node.Value = libMF.FunctionValue[i];
				vMap.AddItemAtTail(node);
			}
		}
	}

	void ReadExpiration() {
		string line;
		cout << "Type Expiration\n";
		cin >> line;

		if (!BracketsCorrectionCheck(line)) {
			cout << "\nOops, check correction of brackets";
			return;
		}
		CalRPN(line);
	}

private:

	bool IsNum(string c) {
		return ("0" <= c && c <= "9") || c == ".";
	}

	void CalRPN(const string& line) {

		string buf;
		for (char c : line) {
			string ch(1, c);

			if (IsNum(ch)) {
				buf += ch;
			}
		}
	}

	bool BracketsCorrectionCheck(string line) {
		sdll_c stack;
		line = DeleteSpace(line);

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

	string DeleteSpace(string line) {
		string new_line = "";

		for (char c : line) {
			if (c != ' ')
				new_line += c;
		}

		return new_line;
	}

};
#endif