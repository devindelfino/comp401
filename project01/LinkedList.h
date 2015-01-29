// LinkedList.h

#ifndef LLIST
#define LLIST

#include "Node.h"

class LinkedList {

private:
	Node* head;
	int size;

public:
    LinkedList();
    ~LinkedList();

    void insert(Node*);
    int get_min();
};