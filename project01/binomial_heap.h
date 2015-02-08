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
	void PrintOut(Node*);					// Recursively prints out subtrees within the Binomial Heap
	Node* SearchSubTree(int, Node*);		// Recursively search through subtrees within the Binomial Heap
public:
	// datamembers
	LinkedList root_list_;					// Contains pointers to roots of each binomial tree

	// constructors/destructors
	BinomialHeap();							// default constructor  
	BinomialHeap(Node*);					// parameterized constructor
	~BinomialHeap();						// destructor

	// main Binomial Heap operations
	void Insert(Node*);						// Inserts a node into the Binomial Heap
	void Insert(int);						// Inserts a node into the Binomial Heap
	void Join(BinomialHeap);				// Joins two heaps into one
	bool IsEmpty();							// Indicates whether or not the heap is empty
	int FindMinimum();						// Finds the minimum key in the binomial heap
	Node* DeleteMinimum();					// Deletes the node with the minimum key in the heap
	void DecreaseKey(Node*, int);			// Decreases the key of a given node in the heap
	void DeleteNode(Node*);					// Deletes a given node from the heap	

	// helper methods
	void LoadData(string);					// Loads integers from a text file into a binomial heap
	void Display();							// Displays each node in the binomial heap
	Node* Search(int);						// Searches the binomial heap for a given key
};
#endif