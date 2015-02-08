/*
 * Project: COMP 401 - Project01
 *
 * Author: Devin Delfino
 *
 * File Name: binomial_heap.cc
 *
 * File Contents: This file contains the implementations of the various constructors and methods of the BinomialHeap class. It supports
 *                a default constructor and a parameterized constructor that can be initialized with a Node pointer. The datamembers
 *                include root_list (a LinkedList containing the roots of each binomial heap). The methods include PrintOut, SearchSubTree, Insert,
 *				  Join, IsEmpty, FindMinimum, DeleteMinimum, DecreaseKey, DeleteNode, LoadData, GetSize, Display, and Search.
 */

#include "binomial_heap.h"

BinomialHeap::BinomialHeap() {
// Default constructor
//    Parameters: None
//    Returns: None
}

BinomialHeap::BinomialHeap(Node* new_node) {
// Parameterized constructor
//    Parameters: None
//    Returns: None
	this->root_list_.InsertRoot(new_node);
}

BinomialHeap::~BinomialHeap() {
// Destructor
//    Parameters: None
//    Returns: None
}

// Main Operations ---------------------------------------------------
void BinomialHeap::Insert(Node* new_node) {
// Inserts a new node into the binomial heap
// Creates a new binomial heap containing new_node and joins it into the binomial heap
//    Parameters: new_node - pointer to the node to insert
//    Returns: None
	new_node->parent_ = NULL;
	new_node->right_sibling_ = NULL;
	BinomialHeap temp_heap = BinomialHeap(new_node);
	this->Join(temp_heap);
}

void BinomialHeap::Insert(int new_key) {
// Inserts a new node into the binomial heap
// Creates a new binomial heap containing a node with new_key and joins it into the binomial heap
//    Parameters: new_key - integer key to insert into the binomial heap
//    Returns: None
	Node* new_node = new Node(new_key);
	BinomialHeap temp_heap = BinomialHeap(new_node);
	this->Join(temp_heap);
}

void BinomialHeap::Join(BinomialHeap b_heap) {
// Joins b_heap into the current binomial heap
//    Parameters: b_heap - a binomial heap to join into the current heap
//    Returns: None
	Node* temp_node = NULL;
	Node* iterator = b_heap.root_list_.head;
	while(iterator != NULL) {
		temp_node = iterator;
		iterator = iterator->right_sibling_;
		this->root_list_.InsertRoot(temp_node);
	}
}

Node* BinomialHeap::DeleteMinimum() {
// Deletes the node in the binomial heap with the minimum key
//    Parameters: None
//    Returns: Node pointer to the deleted node
	int min = this->FindMinimum();
	Node* deleted_node = NULL;

	// find and extract the minimum node from root_list_
	Node* current_node = this->root_list_.head;
	Node* prev_node = NULL;

	while(current_node != NULL) {
		if(current_node->get_key() == min) {
			deleted_node = current_node;
			if(prev_node == NULL) {
				// the minimum node is the head of the root list
				this->root_list_.head = deleted_node->right_sibling_;
			}
			else {
				prev_node->right_sibling_ = deleted_node->right_sibling_;
			}
			break;
		}
		else {
			prev_node = current_node;
			current_node = current_node->right_sibling_;
		}
	}

	// Insert the children_ of the deleted node into a new heap
	BinomialHeap Merge_heap = BinomialHeap();

	Node* temp_node = NULL;
	Node* iterator = deleted_node->children_.head;
	while(iterator != NULL) {
		temp_node = iterator;
		iterator = iterator->right_sibling_;
		Merge_heap.Insert(temp_node);
	}

	cout << "Merged heap from children_" <<endl;
	Merge_heap.Display();
	// Join the original heap with the new Merge_heap containing the children_ of the deleted node
	this->Join(Merge_heap);
	cout << "Deleting Node: ";
	deleted_node->Print();
	cout << endl;
	return deleted_node;
}

bool BinomialHeap::IsEmpty() {
// Determines if the binomial heap is empty or not
//    Parameters: None
//    Returns: boolean indicating if the binomial heap is empty
	if(this->root_list_.head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int BinomialHeap::FindMinimum() {
// Finds the minimum key in the binomial heap
// Since the binomial heap is a collection of min heap trees, the smallest key will always be the root,
// therefore this utilizes the GetMinimum method of the LinkedList class
//    Parameters: None
//    Returns: the minimum integer in the binomial heap
	return this->root_list_.GetMinimum();
}

void BinomialHeap::DecreaseKey(Node* handle, int new_key) {
// Decreases the key of the node given by the pointer 'handle' to new_key
// Utilizes the set_key method of the Node class
//    Parameters: handle  - node pointer to the given node
// 				  new_key - integer representing the new key
//    Returns: None
	cout << "Decreasing key of node ";
	handle->Print();
	cout << " from " << handle->get_key() << " to " << new_key << endl;
	handle->set_key(new_key);
}

void BinomialHeap::DeleteNode(Node* handle) {
// Deletes the node given by the pointer handle
// Decreases the key of the given node to -999999 and then deletes the minimum node
//    Parameters: handle - pointer to the node to delete
//    Returns: None
	cout << "Deleting node ";
	handle->Print();
	this->DecreaseKey(handle, -999999);
	this->DeleteMinimum();
}

// Helper Operations -------------------------------------------------
void BinomialHeap::LoadData(string file_name) {
// Loads integers from a text file into a binomial heap
// Assumes the file has one integer per line
//    Parameters: file_name - a string representing the name of the file (with extension)
//    Returns: None
	ifstream fin;

	fin.open(file_name);

	int new_key;
	while(!fin.eof()) {
		fin >> new_key;
		this->Insert(new_key);
		cout << new_key << " Inserted" <<endl;
	}

	fin.close();
}

void BinomialHeap::Display() {
// Displays each node in the binomial heap using the Print methods of LinkedList
// Calls the recursive PrintOut method on each node in the root_list of the binomial heap
//    Parameters: None
//    Returns: None
	cout << "==========================================" << endl;
	cout << "Root List: ";
	this->root_list_.Print();
	cout << endl;

	Node* temp_node = this->root_list_.head;
	while(temp_node != NULL) {
		cout << "ROOT ==========================================" << endl;
		this->PrintOut(temp_node);
		temp_node = temp_node->right_sibling_;
	}
	cout << "==========================================" << endl;
}

void BinomialHeap::PrintOut(Node* n) {
// Recursively prints out the node and all of its children
//    Parameters: n - node pointer
//    Returns: None
	cout << "--------------------------------------------" << endl;
	n->Print();

	Node* temp_node = n->children_.head;
	while(temp_node != NULL) {
		this->PrintOut(temp_node);
		temp_node = temp_node->right_sibling_;
	}
	cout << "--------------------------------------------" << endl;
}

Node* BinomialHeap::Search(int key_query) {
// Searches the binomial heap for a node with a key equal to key_query
//    Parameters: key_query - integer representing the search query
//    Returns: if key_query is found, returns node pointer to the node with the given key
//             if key_query not found, returns NULL
	Node* handle = NULL;
	Node* temp_node = this->root_list_.head;
	while(temp_node != NULL) {
		handle = this->SearchSubTree(key_query, temp_node);
		if(handle == NULL) {
			temp_node = temp_node->right_sibling_;
		}
		else {
			break;
		}
	}
	return handle;
}

Node* BinomialHeap::SearchSubTree(int key_query, Node* sub_root) {
// Recursively searches through nodes and their children
//    Parameters: key_query - integer representing the key that is being searched for
//                sub_root  - node pointer to the next node to search
//    Returns: if key_query found, returns the node with said key
//             if not found, returns NULL 
	Node* handle = NULL;
	if(sub_root->get_key() == key_query) {
		handle = sub_root;
	}
	else {
		Node* temp_node = sub_root->children_.head;
		while(temp_node != NULL) {
			handle = this->SearchSubTree(key_query, temp_node);
			if(handle == NULL) {
				temp_node = temp_node->right_sibling_;
			}
			else {
				break;
			}
		}
	}
	return handle;
}
