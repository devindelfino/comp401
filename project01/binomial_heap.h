/*
 * Project: COMP 401 - Project01
 *
 * Author: Devin Delfino
 *
 * File Name: binomial_heap.h
 *
 * File Contents: The BinomialHeap class is an implementation of a priority queue consisting of a collection of min heaps
 *				  where the integer key of the parent node is always less than or equal to the integer key of the child nodes.
 *                The class can be used to store integers, with functionality that can easily extract the smallest one and merge
 *                multiple BinomialHeaps together into one.  
 */

#ifndef COMP401_PROJECT01_BINOMIALHEAP_H
#define COMP401_PROJECT01_BINOMIALHEAP_H

#include <iostream>
#include <fstream>
using namespace std;
#include "node.h"
#include "linked_list.h"

// Implementation for a priority queue of integers. Sample Usage:
// 		Node* node1 = new Node(9);
//      BinomialHeap heap_1 = BinomialHeap(node1)
//      heap_1.Display();
class BinomialHeap {
private:
	void PrintOut(Node*);
	Node* SearchSubTree(int, Node*);
public:
	// datamembers
	LinkedList root_list_;

	// constructors/destructors
	BinomialHeap();
	BinomialHeap(Node*);
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