/*
 * Project: COMP 401 - Project01
 *
 * Author: Devin Delfino
 *
 * File Name: node.cc
 *
 * File Contents: This file contains the implementations for the constructors and methods for the Node class.
 *				  The datamembers include a key (the integer being stored), a rank (the number of children the node has), a parent
 *                (node pointer to the parent node), a right_sibling (a node pointer to the next node in its linked list),
 *				  and children (a LinkedList of node pointers to child node). The methods include get_key, set_key,
 *				  get_rank, AddChild, and Print. The Node class includes a parameterized constructor only.
 */

#include "node.h"

Node::Node(int new_key) {
// Constructs a node object with a given integer key
// 	 Parameters: new_key - an integer key (non-negative)
//   Returns: None
	this->key_ = new_key;
	this->right_sibling_ = NULL;
	this->parent_ = NULL;
}

Node::~Node() {
// Destructor
// 	 Parameters: None
//   Returns: None
}

int Node::get_key() {
// Gets the node's integer key
// 	 Parameters: None
//   Returns: the integer key
	return this->key_;
}

int Node::get_rank() {
// Gets the number of child nodes that the node has
// 	 Parameters: None
//   Returns: the integer rank
	return this->rank_;
}

void Node::AddChild(Node* new_node) {
// Adds a node to the LinkedList of children
// 	 Parameters: new_node - Node pointer to the node to be added as a child
//   Returns: None
	new_node->parent_ = this;
	this->children_.InsertChild(new_node);
	this->rank_ += 1;
}

void Node::Print() {
// Prints the key of the node and the keys of its children nodes
// 	 Parameters: None
//   Returns: None
	cout << this->key_ << " : ";
	this->children_.Print();
	cout << endl;
}

void Node::set_key(int new_key) {
// Sets the node's integer key
// 	 Parameters: new_key - the new integer key to replace the previous one
//   Returns: None
	this->key_ = new_key;

	// retain heap-ordering property where children keys are always greater than or equal to its parent key

	if(this->parent_ != NULL) {
		if(this->get_key() < this->parent_->get_key()) {
			this->key_ = this->parent_->get_key();
			this->parent_->set_key(new_key);
		}
	}
}
