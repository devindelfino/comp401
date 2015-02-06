// Node.h

#ifndef COMP401_PROJECT01_NODE_H
#define COMP401_PROJECT01_NODE_H

#include <iostream>
using namespace std;
#include "linked_list.h"

class Node {
private:
	int key;	 			// integer value which is used to determine the heap order property (priority)
	int rank;
public:
	// ---- To customize class, add additional parameters to the Node() constructor (step 1/5) -------
	Node(int);
	// -----------------------------------------------------------------------------------------------
	~Node();

	//void change_key();
	int get_key();
	void update_key(int);
	int get_rank();
	void add_child(Node*);
	void set_right_sibling(Node*);
	void print();

	Node* parent;
	Node* right_sibling;	// used when nodes are part of the linked list of roots
	LinkedList children;

	// ---------- To customize class, add additional parameters here (step 2/5) ----------------------

	// -----------------------------------------------------------------------------------------------
};
#endif