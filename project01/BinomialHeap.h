// BinomialHeap.h

#ifndef BIN_HEAP
#define BIN_HEAP

#include "Node.h"
#include "LinkedList.h"

class BinomialHeap {
private:
	int size;
public:
	BinomialHeap();
	BinomialHeap(int);
	~BinomialHeap();

	LinkedList root_list;

	// methods
	void insert(Node*);
	void join(BinomialHeap);
	Node* delete_min();
	bool is_empty();
	void load_data(string);
	int find_min();
	int get_size();
	void merge(Node*, Node*);
};

#endif