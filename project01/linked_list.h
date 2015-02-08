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

// Contains a series of nodes that can be manipulated in various ways. 
//      Used within the Node and BinomialHeap classes only. 
class LinkedList {
private:
	int size_;                    // the number of nodes in the LinkedList
public:
    LinkedList();                 // default constructor
    ~LinkedList();                // destructor

	Node* head;                   // node pointer to the left-most node in the list
    void InsertRoot(Node*);       // inserts a node into the LinkedList (as root_list of BinomialHeap)
    void InsertChild(Node*);      // inserts a node into the LinkedList (as a child of a Node)
    int GetMinimum();             // Gets the minimum key among the nodes in the LinkedList
    int GetSize();                // Gets the number of nodes in the LinkedList
    void UpdateSize();            // Update the number of nodes in the LinkedList
    void Merge();                 // Merges the LinkedList so no two nodes have the same number of children
    void Print();                 // Prints the key for each node in the LinkedList
};

#endif