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

	class HeadTail {
		//Head - НАЧАЛО СТЕКА (нулевой элемент)
		//Tail - КОНЕЦ (n-ый элемент)
	public:
		Node* Head = NULL;
		Node* Tail = NULL;
	};

	//Функции

private:
	bool EqualData(vec2& data1, vec2& data2) {
		return (data1.real == data2.real) && (data1.imagine == data2.imagine);
	}

	bool EmptyStack(HeadTail& stack) {
		return (stack.Head == NULL) && (stack.Tail == NULL);
	}
public:
	void AddItemAtTail(HeadTail& stack, vec2 data) {

		Node* newNode = new Node();
		newNode->Num = data;

		if (EmptyStack(stack)) {
			stack.Head = newNode;
			stack.Tail = newNode;

			return;
		}

		Node* prevNode = stack.Tail;

		prevNode->Next = newNode;
		newNode->Prev = prevNode;
		stack.Tail = newNode;

	}

	void AddItemAtHead(HeadTail& stack, vec2 data) {

		Node* newNode = new Node();
		newNode->Num = data;

		if (EmptyStack(stack)) {
			stack.Head = newNode;
			stack.Tail = newNode;

			return;
		}

		Node* prevNode = stack.Head;

		prevNode->Prev = newNode;
		stack.Head = newNode;

	}

	void PopHead(HeadTail& stack) {
		if (stack.Head == stack.Tail) {
			stack.Head = NULL;
			stack.Tail = NULL;
			return;
		}

		Node* HeadNode = stack.Head;
		Node* nextNode = HeadNode->Next;

		nextNode->Prev = NULL;
		stack.Head = nextNode;
		delete HeadNode;
	}

	void PopTail(HeadTail& stack) {

		if (stack.Head == stack.Tail) {
			stack.Head = NULL;
			stack.Tail = NULL;
			return;
		}

		Node* TailNode = stack.Tail;
		Node* prevNode = TailNode->Prev;

		prevNode->Next = NULL;
		stack.Tail = prevNode;
		delete TailNode;
		return;

	}

	void DeleteItemFromHead(HeadTail& stack, vec2 data) {
		if (EmptyStack(stack)) {
			return;
		}

		Node* node = stack.Head;
		if (stack.Head == stack.Tail && EqualData(node->Num, data)) {
			stack.Head = NULL;
			stack.Tail = NULL;

			delete node;
			return;
		}

		while (node != NULL) {
			if (EqualData(node->Num, data)) {

				if (node == stack.Head) {
					PopHead(stack);
					return;
				}
				else if (node == stack.Tail) {
					PopTail(stack);
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

	void DeleteItemFromTail(HeadTail& stack, vec2 data) {
		if (EmptyStack(stack)) {
			return;
		}

		Node* node = stack.Tail;
		if (stack.Head == stack.Tail && EqualData(node->Num, data)) {
			stack.Head = NULL;
			stack.Tail = NULL;

			delete node;
			return;
		}

		while (node != NULL) {
			if (EqualData(node->Num, data)) {
				if (node == stack.Head) {
					PopHead(stack);
					return;
				}
				else if (node == stack.Tail) {
					PopTail(stack);
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

	void PrintStack(HeadTail& stack) {

		if (stack.Head == NULL && stack.Tail == NULL) {
			cout << "--Current stack is empty--\n\n";
			return;
		}

		Node* node = stack.Head;
		int c = 0;

		cout << "\n\n--Start Stack Log--\n";

		while (node != NULL) {
			cout << ++c << ". " << node->Num.real << " + " << node->Num.imagine << "i\n";
			node = node->Next;
		}

		cout << "--End Stack Log--\n\n";

	}

	void TestMod(HeadTail& stack) {

		cout << "--Test mode of Node by Voskoboynik--\n$.Stop\nt.Add at tail\nh.Add at head.\nT.Pop tail\nH.Pop head\nd.Delete from tail\nD.Delete from head\n\n";
		char UserInput = 'q';
		vec2 data;
		while (UserInput != '$') {
			cin >> UserInput;
			switch (UserInput) {
			case '$':
				cout << "--Test mod is off--";
				break;
			case 'p':
				PrintStack(stack);
				break;
			case 't':
				cin >> data.real;
				AddItemAtTail(stack, data);
				break;
			case 'h':
				cin >> data.real;
				AddItemAtHead(stack, data);
				break;
			case 'T':
				PopTail(stack);
				break;
			case 'H':
				PopHead(stack);
				break;
			case 'd':
				cin >> data.real;
				DeleteItemFromTail(stack, data);
				break;
			case 'D':
				cin >> data.real;
				DeleteItemFromHead(stack, data);
				break;
			default:
				cout << "Wrong commend\n";
			}
		}
	}

};
