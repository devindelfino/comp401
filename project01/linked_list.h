/*
 * Project: COMP 401 - Project01
 *
 * Author: Devin Delfino
 *
 * File Name: linked_list.h
 *
 * File Contents: The LinkedList class is a data structure that is used ONLY within the BinomialHeap and Node
 *                implementations, so the user will never directly utilize this class. A LinkedList is used to store
 *                the roots of each binomial tree in the BinomialHeap, and also used to store the children of each Node.
 */

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