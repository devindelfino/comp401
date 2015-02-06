// Node.cpp

#include "node.h"

// -----------------------------------------------------------------------------------------------
Node::Node(int new_key) {
	this->key_ = new_key;
	this->right_sibling_ = NULL;
	this->parent_ = NULL;

	// below, add assignments that can alter according to the specific implementation

}

Node::~Node() {
	// delete this->right_sibling_;
}

int Node::get_key() {
	return this->key_;
}

int Node::get_rank() {
	return this->rank_;
}

void Node::set_right_sibling(Node* right) {
	this->right_sibling_ = right;
}

void Node::AddChild(Node* new_node) {
	new_node->parent_ = this;
	this->children_.InsertChild(new_node);
	this->rank_ += 1;
}

void Node::Print() {
	cout << this->key_ << " : ";
	this->children_.Print();
	cout << endl;
}

void Node::set_key(int new_key_) {
	// update key_
	this->key_ = new_key_;

	// retain heap-ordering property where children_ key_s are always greater than or equal to its parent_ key_

	if(this->parent_ != NULL) {
		if(this->get_key() < this->parent_->get_key()) {
			this->key_ = this->parent_->get_key();
			this->parent_->set_key(new_key_);
		}
	}
}

// -----------------------------------------------------------------------------------------------