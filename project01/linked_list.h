// LinkedList.h

#ifndef COMP401_PROJECT01_LINKEDLIST_H
#define COMP401_PROJECT01_LINKEDLIST_H

#include <iostream>
using namespace std;

class Node; // forward declaration of Node to use in LinkedList()

class LinkedList {
private:
	int size_;
public:
    LinkedList();
    ~LinkedList();

	Node* head;
    void InsertRoot(Node*);
    void InsertChild(Node*);
    int GetMinimum();
    int GetSize();
    void UpdateSize();
    void Merge();
    void Print();
};

#endif