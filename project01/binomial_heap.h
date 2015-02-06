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
	int size_;
	void PrintOut(Node*);
	Node* SearchSubTree(int, Node*);
public:
	// datamembers
	LinkedList root_list_;

	// constructors/destructors
	BinomialHeap();
	BinomialHeap(Node*);
	BinomialHeap(LinkedList);
	~BinomialHeap();

	// main Binomial Heap operations
	void Insert(Node*);
	void Insert(int);
	void Join(BinomialHeap);
	bool IsEmpty();
	int FindMinimum();
	Node* DeleteMinimum();
	void DecreaseKey(Node*, int);
	void DeleteNode(Node*);

	// helper methods
	void LoadData(string);
	int GetSize();
	void Display();
	Node* Search(int);
};

#endif