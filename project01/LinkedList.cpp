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
		this->size += 1;
	}
	else {
		// check new node against the head of the linked list
		if(new_node->get_rank() < this->head->get_rank()) {
			new_node->right_sibling = this->head;
			this->head = new_node;
			this->size += 1;

		}
		else if(new_node->get_rank() == this->head->get_rank()) {
			if(new_node->get_key() < this->head->get_key()) {
				new_node->right_sibling = this->head;
				this->head = new_node;
			}
			this->merge(this->head);
		}
		else {
			Node* current_node = this->head->right_sibling;
			Node* prev_node = this->head;
			bool inserted = false;

			while(current_node != NULL) {
				if(new_node->get_rank() > current_node->get_rank()) {
					prev_node = current_node;
					current_node = current_node->right_sibling;
				}
				else { //(new_node->get_rank() <= current_node->get_rank())
					new_node->right_sibling = prev_node->right_sibling;
					prev_node->right_sibling = new_node;
					inserted = true;
					this->merge(prev_node);
					break;
				}

			}
			if(!inserted) {
				prev_node->right_sibling = new_node;
				this->size += 1;
			}
		}
	}
}

void LinkedList::merge(Node* start) {
	Node* prev_node = start;
	Node* current_node = prev_node->right_sibling;
	Node* next_node = NULL;
	while(current_node->right_sibling != NULL) {
		next_node = current_node->right_sibling;
		if(current_node->get_rank() == next_node->get_rank()) {

			if(current_node->get_key() < next_node->get_key()) {
				current_node->right_sibling = next_node->right_sibling;
				current_node->add_child(next_node);

				// prev_node = prev_node;
				// current_node = current_node;
			}
			else { // current_node->get_key() >= next_node->get_key()
				prev_node->right_sibling = next_node;
				next_node->add_child(current_node);

				// prev_node = prev_node;
				current_node = next_node;
			}
		}
		else {
			prev_node = current_node;
			current_node = current_node->right_sibling;
		}
	}
	this->update_size();
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

void LinkedList::update_size() {
	int new_size = 0;
	if(this->head == NULL) {
		//
	}
	else {
		Node* temp_node = this->head;
		while(temp_node != NULL) {
			new_size += 1;
			temp_node = temp_node->right_sibling;
		}
	}
	this->size = new_size;
}
// -----------------------------------------------------------------------------------------------