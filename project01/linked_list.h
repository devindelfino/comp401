// LinkedList.h

#ifndef COMP401_PROJECT01_LINKEDLIST_H
#define COMP401_PROJECT01_LINKEDLIST_H

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
    void insert_root(Node*);
    void insert_child(Node*);
    int get_min();
    int get_size();
    void update_size();
    void merge();
    void print();
};

#endif