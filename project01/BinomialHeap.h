// BinomialHeap.h

#ifndef BIN_HEAP
#define BIN_HEAP

#include "Node.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

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
	void join(BinomialHeap);
	bool is_empty();
	int find_min();
	Node* delete_min();
	void decrease_key(Node*, int);
	// Node* delete(Node*);

	// helper methods
	void load_data(string);
	int get_size();
	void display();
	Node* search(int);
};

#endif