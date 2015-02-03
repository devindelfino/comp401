// LinkedList.h

#ifndef LLIST
#define LLIST

#include <iostream>
using namespace std;

class Node; // forward declaration of Node to use in LinkedList()

class LinkedList {
private:
	int size;
public:
    LinkedList();
    ~LinkedList();

	Node* head;
    void insert(Node*);
    int get_min();
    int get_size();
    void update_size();
    void print();
};

#endif