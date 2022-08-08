#pragma once
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;
    void Swap(Node* elem = 0) {
        int buf = data;
        if (elem)
        {
            data = elem->data;
            elem->data = buf;
        }
    }
};

class LinkedList {

public:
    LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList& list);
   void PushBack(int i);
   void AddBegin(int i);
   void AddAfter(int i, int pos);
   void DisplayElements();
   int Size();
   void RemoveAt(int index);
   Node* At(int index);
   bool IsEmpty();
   LinkedList Sort();
private:
    Node* head;
};
