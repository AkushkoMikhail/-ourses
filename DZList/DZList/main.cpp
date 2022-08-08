

#include "LinkedList.h"

int main()
{
	LinkedList list;
	bool empty = list.IsEmpty();
	list.PushBack(20);
	list.PushBack(10);
	list.PushBack(30);
	list.AddBegin(0);
	list.AddAfter(25, 3);
	list.AddAfter(15, 3);
	list.DisplayElements();
	list.Size();
	 empty = list.IsEmpty();

	list.RemoveAt(list.Size()-1);

	auto newList = list.Sort();

	list.DisplayElements();
	newList.DisplayElements();

	Node* at = list.At(5);

	newList.PushBack(100);
	newList.PushBack(250);

	list.DisplayElements();
	newList.DisplayElements();
	return 0;
}
