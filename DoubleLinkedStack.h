#include <iostream>
#include <stdint.h>
#include "vec2.h"
/*
В основном коде НЕ ПОДКЛЮЧАТЬ <iostream> и <stdint.h> и "vec2.h"
Стек реализован для чисел типа vec2 (для комплексных)

Будет доработан до работы со строками

Функции:

AddItemAtTail() - добавить в конец
AddItemAtHead() - добавить в начало

PopTail() - удалить конец
PopHead() - удалить начало

DeleteItemFromHead(data) - удалить data. Поиск начинается с конца
DeleteItemFromHead(data) - удалить data. Поиск начинается с начала

*/
using namespace std;

class Stack_On_Double_Linked_List {

	class Node {
		//node стека
	public:
		Node* Prev = NULL;
		Node* Next = NULL;

		vec2 Num;
	};

	typedef Stack_On_Double_Linked_List HeadTail;

	Node* Head = NULL;
	Node* Tail = NULL;

	//Функции

private:
	bool EqualData(vec2& data1, vec2& data2) {
		return (data1.real == data2.real) && (data1.imagine == data2.imagine);
	}

	bool EmptyStack() {
		return (Head == NULL) && (Tail == NULL);
	}
public:
	void AddItemAtTail(vec2 data) {

		Node* newNode = new Node();
		newNode->Num = data;

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

	void AddItemAtHead(vec2 data) {

		Node* newNode = new Node();
		newNode->Num = data;

		if (EmptyStack()) {
			Head = newNode;
			Tail = newNode;

			return;
		}

		Node* prevNode = Head;

		prevNode->Prev = newNode;
		Head = newNode;

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

	void DeleteItemFromHead(vec2 data) {
		if (EmptyStack()) {
			return;
		}

		Node* node = Head;
		if (Head == Tail && EqualData(node->Num, data)) {
			Head = NULL;
			Tail = NULL;

			delete node;
			return;
		}

		while (node != NULL) {
			if (EqualData(node->Num, data)) {

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

	void DeleteItemFromTail(vec2 data) {
		if (EmptyStack()) {
			return;
		}

		Node* node = Tail;
		if (Head == Tail && EqualData(node->Num, data)) {
			Head = NULL;
			Tail = NULL;

			delete node;
			return;
		}

		while (node != NULL) {
			if (EqualData(node->Num, data)) {
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

	void PrintStack() {

		if (Head == NULL && Tail == NULL) {
			cout << "--Current stack is empty--\n\n";
			return;
		}

		Node* node = Head;
		int c = 0;

		cout << "\n\n--Start Stack Log--\n";

		while (node != NULL) {
			cout << ++c << ". " << node->Num.real << " + " << node->Num.imagine << "i\n";
			node = node->Next;
		}

		cout << "--End Stack Log--\n\n";

	}

	void TestMod() {

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
				DeleteItemFromTail( data);
				break;
			case 'D':
				cin >> data.real;
				DeleteItemFromHead( data);
				break;
			default:
				cout << "Wrong commend\n";
			}
		}
	}

};
