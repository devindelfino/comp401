// Node.h

#ifndef NODE
#define NODE

#include "LinkedList.h"

class Node {
private:
	int key;	 			// integer value which is used to determine the heap order property (priority)
	Node* right_sibling;	// used when nodes are part of the double linked list of roots

public:
	// ---- To customize class, add additional parameters to the Node() constructor (step 1/5) -------
	Node(int);
	// -----------------------------------------------------------------------------------------------
	~Node();

	//void change_key();
	int get_key();
	void add_child(Node);
	void set_right_sibling(Node*);

	LinkedList children;

	// ---------- To customize class, add additional parameters here (step 2/5) ----------------------

	// -----------------------------------------------------------------------------------------------
};