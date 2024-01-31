template <typename DataType>

class Stack
{
private:
	struct Node
	{
		Node(DataType elem) : element(elem) {} //constructor for by input elem
		Node* next;
		DataType element;
	};
	Node* head; 
	int size;

public:
	Stack() : head(nullptr), size(){};

	void push(DataType elem)
	{
		Node* old_node = head;
		head = new Node(elem);
		head->next = old_node;
		size++;
	}

	void pop()
	{
		if (!isEmpty())
		{
			Node* del = head;
			head = head->next;
			delete del;
			size--;
		}
	}

	
	DataType top() const 
	{
		if (!isEmpty())
			return head->element;
		return 0; 
	}

	bool isEmpty() const
	{
		return size == 0;
	}

public:
	~Stack()
	{
		Node* del = head;
		while (del)
		{
			Node* cur = del;
			del = del->next;
			delete cur;
		}
	}
};
