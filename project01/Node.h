// Node.h

#ifndef NODE
#define NODE

#include <iostream>
using namespace std;
#include "LinkedList.h"

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
	int get_rank();
	void add_child(Node*);
	void set_right_sibling(Node*);
	void print();

	Node* right_sibling;	// used when nodes are part of the double linked list of roots
	LinkedList children;

	// ---------- To customize class, add additional parameters here (step 2/5) ----------------------

	// -----------------------------------------------------------------------------------------------
};
#endif