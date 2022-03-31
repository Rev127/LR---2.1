struct Node;
template<typename Type>
class List
{
public:
	List();
	~List();

	void push_back(Type data);
	void pop_front();
	void push_front(Type data);
	void INSERT(Type data, int index);
	void data_DELETE(int index);
	void pop_back();
	Type RETRIEVE(int index);
	Type LOCATE(Type data);
	Node* FIRST();
	Node* END();
	Node* NEXT(int index);
	Node* PREVIOUS(int index);
	void PRINTLIST();
	void clear();
	void MAKENULL();
	int Get_Size()
	{
		return Size;
	}

	Type& operator [](const int index);

private:

	template<typename Type>
	struct Node
	{
		Node* next;
		Node* prev;
		Type data;

		Node(Type data = Type(), Node* next = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};

	int Size;
	Node<Type>* head;
	Node<Type>* tail;

};

template<typename Type>
List<Type>::List()
{
	Size = 0;
	this->MAKENULL();
}

template<typename Type>
List<Type>::~List()
{
	clear();
}

template<typename Type>
void List<Type>::push_back(Type data)
{
	if (tail == nullptr)
	{
		head = new Node<Type>(data);
		tail = head;
	}
	else
	{
		Node<Type>* current = new Node<Type>(data);
		tail->next = current;
		current->next = nullptr;
		current->prev = this->tail;
		this->tail = current;
	}

	Size++;
}

template<typename Type>
void List<Type>::pop_front()
{
	Node<Type>* temp = head;

	head = head->next;

	delete temp;

	Size--;

}

template<typename Type>
void List<Type>::push_front(Type data)
{
	head = new Node<Type>(data, head);
	Size++;
}

template<typename Type>
void List<Type>::INSERT(Type data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{

		if (index < Size / 2)
		{
			Node<Type>* previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->next;
			}

			Node<Type>* newNode = new Node<Type>(data, previous->next, previous->prev);
			previous->next = newNode;	
			previous->prev = newNode->prev;
		}
		else
		{
			Node<Type>* previous = this->tail;
			for (int i = Size-1; i > index - 1; i--)
			{
				previous = previous->prev;
			}

			Node<Type>* newNode = new Node<Type>(data, previous->next, previous->prev);
			previous->next = newNode;
			previous->prev = newNode->prev;
		}

		Size++;
	}
}

template<typename Type>
void List<Type>::data_DELETE(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{

		if (index < Size / 2)
		{
			Node<Type>* previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->next;
			}

			Node<Type>* ToDelete = previous->next;
			previous->next = ToDelete->next;
			delete ToDelete;

		}
		else
		{
			Node<Type>* previous = this->tail;
			for (int i = Size - 1; i > index; i--)
			{
				previous = previous->prev;
			}

			Node<Type>* ToDelete = previous->next;
			previous->next = ToDelete->next;
			delete ToDelete;
		}

		Size--;
	}
}

template<typename Type>
void List<Type>::pop_back()
{
	data_DELETE(Size - 1);
}

template<typename Type>
Type List<Type>::RETRIEVE(int index)
{
	if (index > Size - 1)
	{
		cout << "Елемент під індексом " << index << " не знайдено!" << endl;
	}
	else
	{

		if (index < Size / 2)
		{
			int counter = 0;
			Node<Type>* current = this->head;

			while (current != nullptr)
			{
				if (counter == index)
				{
					return current->data;
				}
				current = current->next;
				counter++;
			}
		}
		else
		{
			int counter = Size;
			Node<Type>* current = this->tail;
			while (current != nullptr)
			{
				if (counter == index)
				{
					return current->data;
				}
				current = current->prev;
				counter--;
			}
		}
	}
}

template<typename Type>
Type List<Type>::LOCATE(Type data)
{
	int counter = 0;
	Node<Type>* current = this->head;

	for (int i = 0; i < Size; i++)
	{
		if (current->data == data)
		{
			return i;
		}
		current = current->next;
	}

}

template<typename Type>
Node* List<Type>::FIRST()
{
	return head;
}

template<typename Type>
Node* List<Type>::END()
{
	return tail;
}

template<typename Type>
Node* List<Type>::NEXT(int index)
{
	if (index < Size / 2)
	{
		int counter = 0;
		Node<Type>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->next;
			}
			current = current->next;
			counter++;
		}
	}
	else
	{
		int counter = Size;
		Node<Type>* current = this->tail;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->next;
			}
			current = current->prev;
			counter--;
		}
	}
}

template<typename Type>
inline Node* List<Type>::PREVIOUS(int index)
{
	if (index < Size / 2)
	{
		int counter = 0;
		Node<Type>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->prev;
			}
			current = current->next;
			counter++;
		}
	}
	else
	{
		int counter = Size;
		Node<Type>* current = this->tail;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->prev;
			}
			current = current->prev;
			counter--;
		}
	}
}

template<typename Type>
void List<Type>::PRINTLIST()
{
	int value = Size;
	Node<Type>* current = this->head;

	while (value)
	{
		cout << current->data << "; ";
		current = current->next;
		value--;
	}
	cout << endl << endl;
}

template<typename Type>
void List<Type>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename Type>
void List<Type>::MAKENULL()
{
	head = nullptr;
	tail = nullptr;
}

template<typename Type>
Type& List<Type>::operator[](const int index)
{
	int counter = 0;
	Node<Type>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->next;
		counter++;
	}
}
