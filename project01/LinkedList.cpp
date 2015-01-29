// LinkedList.cpp

#include "LinkedList.h"

LinkedList::LinkedList() {
	this->head = NULL;
	this->size = 0;
}

LinkedList::~LinkedList() {
	delete this->head;
}

void LinkedList::insert(Node* new_node) {
	if(this->head == NULL) {
		this->head = new_node;
	}
	else {
		Node* temp_node = this->head;
		while(temp_node->right_sibling != NULL) {
			temp_node = temp_node->right_sibling;
		}
		temp_node->right_sibling = new_node;
	}
	this->size += 1;
}

int LinkedList::get_min() {

	int min = 9999999999;

	if(this->head == NULL) {
		return min;
	}
	else {
		Node* temp_node = this->head;
		while(temp_node != NULL) {
			if(temp_node->key <= min) {
				min = temp_node->key;
			}
			temp_node = temp_node->right_sibling;
		}
		return min;
	}
}