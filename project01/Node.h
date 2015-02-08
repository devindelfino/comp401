/*
 * Project: COMP 401 - Project01
 *
 * Author: Devin Delfino
 *
 * File Name: node.h
 *
 * File Contents: The Node class is a small container used for each node in the binomial heap. This class is ONLY
 *				  meant to be used within the LinkedList and BinomialHeap implementations, so a user will never
 *				  directly utilize the Node class.
 */

#ifndef COMP401_PROJECT01_NODE_H
#define COMP401_PROJECT01_NODE_H

#include <iostream>
using namespace std;
#include "linked_list.h"

// Contains an integer key and various pointers to other nodes within the BinomialHeap.
// 		Used within the LinkedList and BinomialHeap classes only.
class Node {
private:
	int key_;		// integer value which is used to determine the min-heap order property	
	int rank_;		// integer value indicating the number of children the node has
public:
	Node(int);		// parameterized constructor
	~Node();		// destructor

	int get_key();					// Gets the key of the node		
	void set_key(int);				// Sets the key of the node and ensures the min-heap property is satisfied
	int get_rank();					// Gets the rank of the node
	void AddChild(Node*);			// Adds a child node to the LinkedList of children
	void Print();					// Prints the node's key and the keys of its children nodes

	Node* parent_;					// pointer to the parent node of this node
									// used to maintain heap order property in set_key()
	Node* right_sibling_;			// pointer to the next node in the linked list
									// used when nodes are part of the linked list of roots or children
	LinkedList children_;			// LinkedList of children nodes
};
#endif