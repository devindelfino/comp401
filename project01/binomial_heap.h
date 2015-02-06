// BinomialHeap.h

#ifndef COMP401_PROJECT01_BINOMIALHEAP_H
#define COMP401_PROJECT01_BINOMIALHEAP_H

#include <iostream>
#include <fstream>
using namespace std;
#include "node.h"
#include "linked_list.h"

class BinomialHeap {
private:
	int size;
	void print_out(Node*);
	Node* search_subtree(int, Node*);
public:
	// datamembers
	LinkedList root_list;

	// constructors/destructors
	BinomialHeap();
	BinomialHeap(Node*);
	BinomialHeap(LinkedList);
	~BinomialHeap();

	// main Binomial Heap operations
	void insert(Node*);
	void insert(int);
	void join(BinomialHeap);
	bool is_empty();
	int find_min();
	Node* delete_min();
	void decrease_key(Node*, int);
	void delete_node(Node*);

	// helper methods
	void load_data(string);
	int get_size();
	void display();
	Node* search(int);
};

#endif