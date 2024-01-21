#pragma once

#include "DoubleLinkedStack.h"
#include "MathFunctions.h"

typedef Stack_On_Double_Linked_List<vec2> sdll_vec;
typedef Stack_On_Double_Linked_List<string> sdll_str;
typedef Stack_On_Double_Linked_List<char> sdll_c;
typedef Stack_On_Double_Linked_List<HashMap> Map;

/*

Есть функция на проверку скобок ( '(' и ')' ) и удаление пробелов - BracketsCorrectionCheck(line), DeleteSpace(line) соотв. 

Для получение стоимости (приоритет) каждой функции в виде HashMap используется функция ConnectHash()
Названия функций, а также их веса заранее лежат в "MathFunctions.h"

*/

class GetPolishNotation {

private:
	sdll_str op;
	sdll_vec nums;
	Map vMap;

public:

	void ReadExpiration() {
		string line;
		cout << "Type Expiration\n";
		cin >> line;

		if (!BracketsCorrectionCheck(line)) {
			cout << "\nOops, check correction of brackets";
			return;
		}
		ConnectHash();
		vMap.PrintStack();
		CalRPN(line);
	}

private:

	void ConnectHash() {
		MathFunctions libMF;

		for (int i = 0; i < _FUNCTION_NAME_ARRAY_SIZE_; i++) {
			if (libMF.FunctionValue[i]) {

				HashMap node;
				node.Key = libMF.FunctionNames[i];
				node.Value = libMF.FunctionValue[i];
				vMap.AddItemAtTail(node);
			}
		}
	}

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