// Node.h

#ifndef COMP401_PROJECT01_NODE_H
#define COMP401_PROJECT01_NODE_H

#include <iostream>
using namespace std;
#include "linked_list.h"

class Node {
private:
	int key_;	 			// integer value which is used to determine the heap order property (priority)
	int rank_;
public:
	// ---- To customize class, add additional parameters to the Node() constructor (step 1/5) -------
	Node(int);
	// -----------------------------------------------------------------------------------------------
	~Node();

	int get_key();
	void set_key(int);
	int get_rank();
	void AddChild(Node*);
	void set_right_sibling(Node*);
	void Print();

	Node* parent_;
	Node* right_sibling_;	// used when nodes are part of the linked list of roots
	LinkedList children_;

	// ---------- To customize class, add additional parameters here (step 2/5) ----------------------

	// -----------------------------------------------------------------------------------------------
};
#endif