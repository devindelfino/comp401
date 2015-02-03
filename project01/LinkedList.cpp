// LinkedList.cpp

#include "LinkedList.h"
#include "Node.h"
// -----------------------------------------------------------------------------------------------
LinkedList::LinkedList() {
	this->head = NULL;
	this->size = 0;
}

LinkedList::~LinkedList() {
	delete this->head;
}

void LinkedList::insert(Node* new_node) {
	// if(this->head == NULL) {
	// 	this->head = new_node;
	// }
	// else {
	// 	Node* temp_node = this->head;
	// 	while(temp_node->right_sibling != NULL) {
	// 		temp_node = temp_node->right_sibling;
	// 	}
	// 	temp_node->right_sibling = new_node;
	// }

	if(this->head == NULL) {
		this->head = new_node;
	}
	else {
		// check new node against the head of the linked list
		if(new_node->get_rank() < this->head->get_rank()) {
			new_node->right_sibling = this->head;
			this->head = new_node;
			this->size += 1;
		}
		else if(new_node->get_rank() == this->head->get_rank()) {
			//merge and reassign head
		}
		else {
			Node* current_node = this->head;
			Node* prev_node = this->head;
			while(current_node != NULL) {
				if(new_node->get_rank() > current_node->get_rank()) {
					
				}
				else {	// new_node->get_rank() == current_node->get_rank()

				}
			}
		}



		new_node->right_sibling = this->head;
		this->head = new_node;

		Node* temp_node = this->head;
		while(temp_node != NULL) {
			if(temp_node->get_rank() == temp_node->right_sibling->get_rank()) {
				//merge
				if(new_node->get_key() <= new_node->right_sibling->get_key()) {
					new_node->add_child(new_node->right_sibling);
				}
			}
		}
	}
	this->size += 1;
}

int LinkedList::get_min() {

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
			temp_node = temp_node->right_sibling;
		}
		return min;
	}
}

int LinkedList::get_size() {
	return this->size;
}

void LinkedList::print() {
	if(this->head == NULL) {
		cout << "[ ]" << endl;
	}
	else {
		Node* temp_node = this->head;
		cout << "[ ";
		while(temp_node != NULL) {
			cout << temp_node->get_key() << " ";
			temp_node = temp_node->right_sibling;
		}
		cout << "]" << endl;
	}
}
// -----------------------------------------------------------------------------------------------