// LinkedList.h

#ifndef LLIST
#define LLIST

#include <iostream>
using namespace std;

class Node; // forward declaration of Node to use in LinkedList()

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

#endif