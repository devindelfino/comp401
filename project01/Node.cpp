// Node.cpp

#include "Node.h"
// -----------------------------------------------------------------------------------------------
Node::Node(int new_key) {
	this->key = new_key;
	this->right_sibling = NULL;
	this->parent = NULL;

	// below, add assignments that can alter according to the specific implementation

}

Node::~Node() {
	// delete this->right_sibling;
}

int Node::get_key() {
	return this->key;
}

int Node::get_rank() {
	return this->rank;
}

void Node::set_right_sibling(Node* right) {
	this->right_sibling = right;
}

void Node::add_child(Node* new_node) {
	new_node->parent = this;
	this->children.insert_child(new_node);
	this->rank += 1;
}

void Node::print() {
	cout << this->key << " : ";
	this->children.print();
	cout << endl;
}

void Node::update_key(int new_key) {
	// update key
	this->key = new_key;

	// retain heap-ordering property where children keys are always greater than or equal to its parent key

	if(this->parent != NULL) {
		if(this->get_key() < this->parent->get_key()) {
			this->key = this->parent->get_key();
			this->parent->update_key(new_key);
		}
	}
}

// -----------------------------------------------------------------------------------------------