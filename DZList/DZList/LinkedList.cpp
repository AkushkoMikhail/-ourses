#include "LinkedList.h"

#include <vector>

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::LinkedList(const LinkedList& linked):head(linked.head)
{
}


LinkedList& LinkedList::operator=(const LinkedList& linked)
{
	if (this == &linked)
	{
		return *this;
	}
	head = linked.head;
	return *this;
}

void LinkedList::PushBack(int i)
{
	Node* element = new Node();
	element->data = i;
	element->next = nullptr;
	cout << "PushBack" << endl;
	if (!head)
	{
		element->prev = NULL;
		head = element;
	}
	else
	{
		Node* other = head;
		while (other->next != NULL)
			other = other->next;
		other->next = element;
		element->prev = other;
	}
}

void LinkedList::AddBegin(int i)
{
	if (!head)
	{
		PushBack(i);
		return;
	}
	Node* newElement = new Node();
	newElement->prev = NULL;
	newElement->data = i;
	newElement->next = head;
	head->prev = newElement;
	head = newElement;
	cout << "AddBegin complete" << endl;
}

void LinkedList::AddAfter(int value, int pos)
{
	if (!head)
	{
		cout << "First Create the list." << endl;
		return;
	}
	Node* element = head;
	for (int i = 0; i < pos; i++)
	{
		element = element->next;
		if (!element)
		{
			cout << "There are less than ";
			cout << pos << " elements." << endl;
			return;
		}
	}
	Node* tmp = new Node();
	tmp->data = value;
	if (!element->next)
	{
		element->next = tmp;
		tmp->next = nullptr;
		tmp->prev = element;
	}
	else
	{
		tmp->next = element->next;
		tmp->next->prev = tmp;
		element->next = tmp;
		tmp->prev = element;
	}
	cout << "Element Inserted" << endl;
}

void LinkedList::DisplayElements()
{
	Node* next = new Node();
	if (!head)
	{
		cout << "List empty" << endl;
		return;
	}
	next = head;
	while (next)
	{
		cout << next->data << " <-> ";
		next = next->next;
	}
	cout << "NULL" << endl;
}

int LinkedList::Size()
{
	if (!head)
		return 0;
	Node* element = head;
	int size = 0;
	while (element != NULL)
	{
		element = element->next;
		size++;
	}
	cout << "Size: " << size << endl;
	return size;
}

void LinkedList::RemoveAt(int index)
{
	if (!head)
	{
		cout << "List empty" << endl;
		return;
	}
	Node* element = head;
	for (int i = 0; i < index; i++)
	{
		element = element->next;
		if (!element)
		{
			cout << "There are less than ";
			cout << index << " elements." << endl;
			return;
		}
	}
	auto prev = element->prev;
	auto next = element->next;
	prev->next = next;
	if (next)
		next->prev = prev;
}

Node* LinkedList::At(int index)
{
	Node* element = 0;
	for (element = head; element && index; element = element->next)
		index--;
	return element;
}

bool LinkedList::IsEmpty()
{
	bool isEmpty = head == nullptr;
	cout << "IsEmpty: " << isEmpty << endl;
	return isEmpty;
}


LinkedList LinkedList::Sort()
{
	LinkedList linked = LinkedList(*this);
	Node* current;
	Node* next;
	int _size = Size();
	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++)
		{
			current = linked.At(i);
			next = linked.At(j);
			if (current && next)
			{
				if ((current->data < next->data))
					current->Swap(next);
			}
		}
	return linked;
}
