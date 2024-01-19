#include <iostream>
#include <typeinfo>
#include <string>
#include <stdint.h>

#include "vec2.h"

#ifndef _Short_Func_Names_
#define _Short_Func_Names_

#define pop PopTail
#define popH PopHead

#define add AddItemAtTail
#define addH AddItemAtHead

#define del DeleteItemFromTail
#define delH DeleteItemFromHead

#define print PrintStack

#define tmVec2 TestModVec
#define tmStr TestModString

#endif

/*
В основном коде НЕ ПОДКЛЮЧАТЬ библиотеки, которые уже включены тут
Стек реализован для чисел типа vec2 (для комплексных)

Будет доработан до работы со строками

Применять в main:
Чтобы получить стек из комп.чисел нужно прописать:
typedef Stack_On_Double_Linked_List<vec2> "название";
TestModVec() - tmVec() - режим тестирования

Чтобы получить стек из строк нужно прописать:
typedef Stack_On_Double_Linked_List<string> "название";
TestModString() - tmStr() - режим тестирования

Функции:

AddItemAtTail() - add() - добавить в конец
AddItemAtHead() - addH() - добавить в начало

PopTail() - pop() - удалить конец
PopHead() - popH() -удалить начало

DeleteItemFromHead(data) - удалить data. Поиск начинается с конца
DeleteItemFromHead(data) - удалить data. Поиск начинается с начала

*/

/*Test main
#include "DoubleLinkedStack.h"

typedef Stack_On_Double_Linked_List<vec2> sdll_vec;
typedef Stack_On_Double_Linked_List<string> sdll_str;

int main() {
	sdll_vec line;
	for (int i = 0; i < 10; i++) {
		vec2 ComplexNum;
		ComplexNum.real = i;

		line.add(ComplexNum);
	}

	line.print();

	sdll_str line1;

	string s = "Hello world";
	string s1 = "Bye world";

	line1.add(s);
	line1.add(s1);
	line1.print();

	line1.addH(s1);
	line1.addH(s);
	line1.print();

	line1.del(s);
	line1.print();
	line1.delH(s1);
	line1.print();

	return 0;
}

*/

using namespace std;

template <class DataType>

class Stack_On_Double_Linked_List {

	class Node {
		//node стека
	public:
		Node* Prev = NULL;
		Node* Next = NULL;

		DataType Val;
	};

	Node* Head = NULL;
	Node* Tail = NULL;


	//Функции
private:
	bool EqualData(DataType& data1, DataType& data2) {

		if constexpr (is_same<DataType, vec2>::value) {
			return (data1.real == data2.real) && (data1.imagine == data2.imagine);
		}
		else if constexpr (is_same<DataType, string>::value) {
			return data1 == data2;
		}
	}

	bool EmptyStack() {
		return (Head == NULL) && (Tail == NULL);
	}

public:
	void AddItemAtTail(DataType data) {

		Node* newNode = new Node();
		newNode->Val = data;

		if (EmptyStack()) {
			Head = newNode;
			Tail = newNode;

			return;
		}

		Node* prevNode = Tail;

		prevNode->Next = newNode;
		newNode->Prev = prevNode;
		Tail = newNode;

	}

	void AddItemAtHead(DataType data) {

		Node* newNode = new Node();
		newNode->Val = data;

		if (EmptyStack()) {
			Head = newNode;
			Tail = newNode;

			return;
		}

		Node* nextNode = Head;

		nextNode->Prev = newNode;
		newNode->Next = nextNode;
		Head = newNode;

	}

	void PopTail() {

		if (Head == Tail) {
			Head = NULL;
			Tail = NULL;
			return;
		}

		Node* TailNode = Tail;
		Node* prevNode = TailNode->Prev;

		prevNode->Next = NULL;
		Tail = prevNode;
		delete TailNode;
		return;

	}

	void PopHead() {
		if (Head == Tail) {
			Head = NULL;
			Tail = NULL;
			return;
		}

		Node* HeadNode = Head;
		Node* nextNode = HeadNode->Next;

		nextNode->Prev = NULL;
		Head = nextNode;
		delete HeadNode;
	}

	void DeleteItemFromTail(DataType data) {
		if (EmptyStack()) {
			return;
		}

		Node* node = Tail;
		if (Head == Tail && EqualData(node->Val, data)) {
			Head = NULL;
			Tail = NULL;

			delete node;
			return;
		}

		while (node != NULL) {
			if (EqualData(node->Val, data)) {
				if (node == Head) {
					PopHead();
					return;
				}
				else if (node == Tail) {
					PopTail();
					return;
				}

				Node* prevNode = node->Prev;
				Node* nextNode = node->Next;

				prevNode->Next = nextNode;
				delete node;
				return;
			}
			node = node->Prev;
		}
	}

	void DeleteItemFromHead(DataType data) {
		if (EmptyStack()) {
			return;
		}

		Node* node = Head;
		if (Head == Tail && EqualData(node->Val, data)) {
			Head = NULL;
			Tail = NULL;

			delete node;
			return;
		}

		while (node != NULL) {
			if (EqualData(node->Val, data)) {

				if (node == Head) {
					PopHead();
					return;
				}
				else if (node == Tail) {
					PopTail();
					return;
				}

				Node* prevNode = node->Prev;
				Node* nextNode = node->Next;

				prevNode->Next = nextNode;
				delete node;
				return;
			}
			node = node->Next;
		}
	}

	void PrintStack() {

		if (Head == NULL && Tail == NULL) {
			cout << "\n\n--Current stack is empty--\n\n";
			return;
		}

		Node* node = Head;
		int c = 0;

		cout << "\n\n--Start Stack Log--\n";

		if constexpr (is_same<DataType, vec2>::value) {
			while (node != NULL) {
				cout << ++c << ". " << node->Val.real << " + " << node->Val.imagine << "i\n";
				node = node->Next;
			}
		}else if constexpr(is_same<DataType, string>::value) {
			while (node != NULL) {
				cout << ++c << ". " << node->Val << "\n";
				node = node->Next;
			}
		}

		cout << "--End Stack Log--\n\n";

	}

	void TestModVec() {

		cout << "--Test mode of Node by Voskoboynik--\n$.Stop\nt.Add at tail\nh.Add at head.\nT.Pop tail\nH.Pop head\nd.Delete from tail\nD.Delete from head\n\n";
		char UserInput = ' ';

		vec2 data;

		while (UserInput != '$') {
			cin >> UserInput;
			switch (UserInput) {
			case '$':
				cout << "--Test mod is off--";
				break;
			case 'p':
				PrintStack();
				break;
			case 't':

				cin >> data.real;
				AddItemAtTail(data);
				break;
			case 'h':

				cin >> data.real;
				AddItemAtHead(data);
				break;
			case 'T':
				PopTail();
				break;
			case 'H':
				PopHead();
				break;
			case 'd':

				cin >> data.real;
				DeleteItemFromTail(data);
				break;
			case 'D':

				cin >> data.real;
				DeleteItemFromHead(data);
				break;
			default:
				cout << "Wrong commend\n";
				break;
			}
		}
	}

	void TestModString() {

		cout << "--Test mode of Node by Voskoboynik--\n$.Stop\nt.Add at tail\nh.Add at head.\nT.Pop tail\nH.Pop head\nd.Delete from tail\nD.Delete from head\n\n";
		char UserInput = ' ';

		string data;

		while (UserInput != '$') {
			cin >> UserInput;
			switch (UserInput) {
			case '$':
				cout << "--Test mod is off--";
				break;
			case 'p':
				PrintStack();
				break;
			case 't':

				cin >> data;
				AddItemAtTail(data);
				break;
			case 'h':

				cin >> data;
				AddItemAtHead(data);
				break;
			case 'T':
				PopTail();
				break;
			case 'H':
				PopHead();
				break;
			case 'd':

				cin >> data;
				DeleteItemFromTail(data);
				break;
			case 'D':

				cin >> data;
				DeleteItemFromHead(data);
				break;
			default:
				cout << "Wrong commend\n";
				break;
			}
		}
	}

};
