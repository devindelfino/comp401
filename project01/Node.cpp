// Node.cpp

#include "Node.h"

// ---------- To customize class, update parameters and assigments (step 3/5) ----------------------
Node::Node(int new_key) {
	this->key = new_key;
	this->right_sibling = NULL;

	// below, add assignments that can alter according to the specific implementation

}
// -----------------------------------------------------------------------------------------------

Node::~Node() {
	delete this->right_sibling;
}

int Node::get_key() {
	return this->key;
}

void Node::set_right_sibling(Node* right) {
	this->right_sibling = right;
}

void Node::add_child(Node new_node) {
	this->children.insert(new_node);
}