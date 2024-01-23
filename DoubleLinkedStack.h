#pragma once

#ifndef _STACK_ON_DOUBLE_LINKED_LIST_
#define _STACK_ON_DOUBLE_LINKED_LIST_

//#define _TEST_MODS_
#include <iostream>

template <class DataType>
//Stack based on double linked list
class SDLL {

	//node стека
	class Node {
	public:
		Node():Prev(NULL), Next(NULL),Val(){}
		Node* Prev;
		Node* Next;

		DataType Val;
	};
public:
	SDLL():Head(NULL),Tail(NULL){}
	Node* Head;
	Node* Tail;

	//Функции
private:

	bool EqualData(const DataType& data1, const DataType& data2) {

		return data1 == data2;
	}
public:
	bool empty() {
		return (Head == NULL) && (Tail == NULL);
	}

	DataType get() {
		return Tail->Val;
	}

	DataType find(const DataType& data) {
		Node* node = Tail;
		while (node != NULL) {

			if (EqualData(node->Val, data)) {
				return node->Val;
			}
			node = node->Prev;
		}
		return NULL;
	}

	DataType findH(const DataType& data) {
		Node* node = Head;
		while (node != NULL) {

			if (EqualData(node->Val, data)) {
				return node->Val;
			}
			node = node->Next;
		}
		return NULL;
	}

	DataType getH() {
		return Head->Val;
	}

	void add(const DataType& data) {

		Node* newNode = new Node();
		newNode->Val = data;

		if (empty()) {
			Head = newNode;
			Tail = newNode;

			return;
		}

		Node* prevNode = Tail;

		prevNode->Next = newNode;
		newNode->Prev = prevNode;
		Tail = newNode;

	}

	void addH(const DataType& data) {

		Node* newNode = new Node();
		newNode->Val = data;

		if (empty()) {
			Head = newNode;
			Tail = newNode;

			return;
		}

		Node* nextNode = Head;

		nextNode->Prev = newNode;
		newNode->Next = nextNode;
		Head = newNode;

	}

	DataType pop() {

		if (Head == Tail) {
			DataType Save = Tail->Val;
			Head = NULL;
			Tail = NULL;
			return Save;
		}
		DataType TailNodeSave = Tail->Val;
		Node* TailNode = Tail;
		Node* prevNode = TailNode->Prev;

		prevNode->Next = NULL;
		Tail = prevNode;

		delete TailNode;
		return TailNodeSave;
	}

	DataType popH() {
		if (Head == Tail) {
			DataType Save = Head->Val;
			Head = NULL;
			Tail = NULL;
			return Save;
		}

		DataType HeadNodeSave = Head->Val;
		Node* HeadNode = Head;
		Node* nextNode = HeadNode->Next;

		nextNode->Prev = NULL;
		Head = nextNode;
		delete HeadNode;
		return HeadNodeSave;
	}

	void del(const DataType& data) {
		if (empty()) {
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
					popH();
					return;
				}
				else if (node == Tail) {
					pop();
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

	void delH (const DataType& data) {
		if (empty()) {
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
					popH();
					return;
				}
				else if (node == Tail) {
					pop();
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

	void print() const {

		if (Head == NULL && Tail == NULL) {
			std::cout << "\n\n--Current stack is empty--\n\n";
			return;
		}

		Node* node = Head;
		int c = 0;

		std::cout << "\n\n--Start Stack Log--\n";

		while (node != NULL) {
			std::cout << ++c << ". " << node->Val << "\n";
			node = node->Next;
		}

		std::cout << "--End Stack Log--\n\n";
	}

#ifdef _TEST_MODS_
	void TestModVec() const {

		std::cout << "--Test mode of Node by Voskoboynik (m)--\n\n";
		char UserInput = ' ';

		vec2 data;

		while (UserInput != '$') {
			std::cin >> UserInput;
			switch (UserInput) {
			case '$':
				std::cout << "--Test mod is off--";
				break;
			case 'm':
				std::cout << "--Menu--\n$.Stop\nt.Add at tail\nh.Add at head.\nT.Pop tail\nH.Pop head\nd.Delete from tail\nD.Delete from head\n\n";
				break;
			case 'p':

				print();
				break;
			case 't':

				std::cin >> data.real;
				add(data);
				break;
			case 'h':

				std::cin >> data.real;
				addH(data);
				break;
			case 'T':

				pop();
				break;
			case 'H':

				popH();
				break;
			case 'd':

				std::cin >> data.real;
				del(data);
				break;
			case 'D':

				std::cin >> data.real;
				delH(data);
				break;
			default:
				std::cout << "Wrong commend\n";
				break;
			}
		}
	}

	void TestModString() const {

		std::cout << "--Test mode of Node by Voskoboynik (m)--\n\n";
		char UserInput = ' ';

		std::string data;

		while (UserInput != '$') {
			std::cin >> UserInput;
			switch (UserInput) {
			case '$':
				std::cout << "--Test mod is off--";
				break;
			case 'm':
				std::cout << "--Menu--\n$.Stop\nt.Add at tail\nh.Add at head.\nT.Pop tail\nH.Pop head\nd.Delete from tail\nD.Delete from head\n\n";
				break;
			case 'p':

				print();
				break;
			case 't':

				std::cin >> data;
				add(data);
				break;
			case 'h':

				std::cin >> data;
				addH(data);
				break;
			case 'T':

				pop();
				break;
			case 'H':

				popH();
				break;
			case 'd':

				std::cin >> data;
				del(data);
				break;
			case 'D':

				std::cin >> data;
				delH(data);
				break;
			default:
				std::cout << "Wrong commend\n";
				break;
			}
		}
	}
#endif
};

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

/*
Стек поддерживает почти все типы

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

DeleteItemFromHead(data) - del(data) - удалить data. Поиск начинается с конца
DeleteItemFromHead(data) - delH(data) - удалить data. Поиск начинается с начала

find(data) - find(data) - ДЛЯ HASHMAP - возвращает значение по ключу. Поиск с конца
FindItemFromHead(data) - findH(data) - ДЛЯ HASHMAP - возвращает значение по ключу. Поиск с начала

empty() - empty() - пустой ли стек или нет
*/
#endif