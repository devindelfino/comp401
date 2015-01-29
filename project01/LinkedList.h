// LinkedList.h

#ifndef LLIST
#define LLIST

#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList {

private:
	Node* head;
	int size;

public:
    LinkedList();
    ~LinkedList();

    void insert(Node*);
    int get_min();
    void print();
};