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
	this->children.insert_child(new_node);
	this->rank += 1;
}

void Node::print() {
	cout << this->key << " : ";
	this->children.print();
	cout << endl;
}
// -----------------------------------------------------------------------------------------------