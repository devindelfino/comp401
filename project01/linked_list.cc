/*
 * Project: COMP 401 - Project01
 *
 * Author: Devin Delfino
 *
 * File Name: linked_list.cc
 *
 * File Contents: This file contains the implementations for the various constructors and methods of the LinkedList class.
 *				  The datamembers include size (number of nodes in the linked list) and head (the pointer to the leftmost
 *                node of the list). The methods include InsertRoot, InsertChild, GetMinimum, GetSize, UpdateSize, Merge,
 *                and Print. It includes a default constructor only.  
 */

#include "linked_list.h"
#include "node.h"

// -----------------------------------------------------------------------------------------------
LinkedList::LinkedList() {
// Default Constructor
// 	 Parameters: None
//   Returns: None
	this->head = NULL;
	this->size_ = 0;
}

LinkedList::~LinkedList() {
// Destructor
// 	 Parameters: None
//   Returns: None
}

void LinkedList::InsertRoot(Node* new_node) {
// Inserts a node in a LinkedList. Its placement depends on its rank (insersion sort by rank)
// 	 Parameters: new_node - pointer to the node to be added to the root list
//   Returns: None
	new_node->parent_ = NULL;
	new_node->right_sibling_ = NULL;
	// simply insert if the list is empty
	if(this->head == NULL) {
		this->head = new_node;
		this->size_ += 1;
	}
	// if the list is NOT empty
	else {
		// insert at head of list if the rank is less than the current head's rank
		if(new_node->get_rank() < this->head->get_rank()) {
			new_node->right_sibling_ = this->head;
			this->head = new_node;
			this->size_ += 1;
		}
		// if the new node has the same rank as the current head and has a smaller key
		// insert the new node at the head of the list
		else if((new_node->get_rank() == this->head->get_rank()) && (new_node->get_key() < this->head->get_key())) {
			new_node->right_sibling_ = this->head;
			this->head = new_node;
		}
		// if the new node's rank is greater than or equal to the head node's rank
		else {
			Node* current_node = this->head->right_sibling_;
			Node* prev_node = this->head;
			bool not_Inserted = true;

			while(current_node != NULL) {
				if(new_node->get_rank() > current_node->get_rank()) {
					prev_node = current_node;
					current_node = current_node->right_sibling_;
				}
				else { //(new_node->get_rank() <= current_node->get_rank())
					new_node->right_sibling_ = prev_node->right_sibling_;
					prev_node->right_sibling_ = new_node;
					not_Inserted = false;
					break;
				}
			}
			if(not_Inserted) {
				prev_node->right_sibling_ = new_node;
				this->size_ += 1;
			}
		}
		this->Merge();
	}
}

void LinkedList::InsertChild(Node* new_node) {
// Inserts a node into a LinkedList always at the head of the list (left-most)
// 	 Parameters: new_node - pointer to the node to be added
//   Returns: None
	if(this->head == NULL) {
		this->head = new_node;
		this->head->right_sibling_ = NULL;
		this->size_ += 1;
	}
	else {
		new_node->right_sibling_ = this->head;
		this->head = new_node;
		this->size_ += 1;
	}
	this->Merge();
}

void LinkedList::Merge() {
// Merges the LinkedList so no two roots have the same rank
// Used to merge the root_list of a BinomialHeap class
// 	 Parameters: None
//   Returns: None
	Node* prev_node = NULL;
	Node* current_node = NULL;
	Node* next_node = NULL;

	// merging the first two nodes of the list requires a special loop
	// in order to ensure the head pointer always points at the leftmost node
	while(this->head->right_sibling_ != NULL && this->head->get_rank() == this->head->right_sibling_->get_rank()) {
		current_node = this->head;
		next_node = this->head->right_sibling_;
		if(current_node->get_key() <= next_node->get_key()) {
			current_node->right_sibling_ = next_node->right_sibling_;
			current_node->AddChild(next_node);
		}
		else {	// current_node->get_key() > next_node->get_key()
			this->head = next_node;
			next_node->AddChild(current_node);
		}

	}

	// after the head node is not required to be merged with its successor,
	// continue checking for the need to merge if there are greater than 1 node still in the root_list
	if(this->head->right_sibling_ != NULL) {
		prev_node = this->head;
		current_node = this->head->right_sibling_;

		// continue the loop until each node in the list has a distinct rank
		while(current_node->right_sibling_ != NULL) {
			next_node = current_node->right_sibling_;
			if(current_node->get_rank() == next_node->get_rank()) {

				if(current_node->get_key() < next_node->get_key()) {
					current_node->right_sibling_ = next_node->right_sibling_;
					// next_node->parent_ = current_node;
					current_node->AddChild(next_node);

					// prev_node = prev_node;
					// current_node = current_node;
				}
				else { // current_node->get_key() >= next_node->get_key()
					prev_node->right_sibling_ = next_node;
					// current_node->parent_ = next_node;
					next_node->AddChild(current_node);

					// prev_node = prev_node;
					current_node = next_node;
				}
			}
			else {
				prev_node = current_node;
				current_node = current_node->right_sibling_;
			}
		}
	}
	// update the size of the list after the merge takes place
	this->UpdateSize();
}

int LinkedList::GetMinimum() {
// Gets the minimum key in the LinkedList
// 	 Parameters: None
//   Returns: the smallest integer key
	int min = 999999;

	if(this->head == NULL) {
		return min;
	}
	else {
		Node* temp_node = this->head;
		while(temp_node != NULL) {
			if(temp_node->get_key() <= min) {
				min = temp_node->get_key();
			}
			temp_node = temp_node->right_sibling_;
		}
		return min;
	}
}

int LinkedList::GetSize() {
// Gets the number of nodes in the LinkedList
// 	 Parameters: None
//   Returns: the integer size
	return this->size_;
}

void LinkedList::Print() {
// Prints the key of each node in the LinkedList
// 	 Parameters: None
//   Returns: None
	if(this->head == NULL) {
		cout << "[ ]" << endl;
	}
	else {
		Node* temp_node = this->head;
		cout << "[ ";
		while(temp_node != NULL) {
			cout << temp_node->get_key() << " ";
			temp_node = temp_node->right_sibling_;
		}
		cout << "]" << endl;
	}
}

void LinkedList::UpdateSize() {
// Updates the current size of the LinkedList
// Used after a merge, because multiple pairs of nodes in the list may be consolidated into one
// 	 Parameters: None
//   Returns: None
	int new_size = 0;
	if(this->head == NULL) {
		//
	}
	else {
		Node* temp_node = this->head;
		while(temp_node != NULL) {
			new_size += 1;
			temp_node = temp_node->right_sibling_;
		}
	}
	this->size_ = new_size;
}
