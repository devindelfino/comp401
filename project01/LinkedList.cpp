// LinkedList.cpp

#include "LinkedList.h"
#include "Node.h"
// -----------------------------------------------------------------------------------------------
LinkedList::LinkedList() {
	this->head = NULL;
	this->size = 0;
}

LinkedList::~LinkedList() {
	// delete this->head;
}

void LinkedList::insert_root(Node* new_node) {
	new_node->parent = NULL;
	new_node->right_sibling = NULL;
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
		else if((new_node->get_rank() == this->head->get_rank()) && (new_node->get_key() < this->head->get_key())) {
			new_node->right_sibling = this->head;
			this->head = new_node;
		}
		else {
			Node* current_node = this->head->right_sibling;
			Node* prev_node = this->head;
			bool not_inserted = true;

			while(current_node != NULL) {
				if(new_node->get_rank() > current_node->get_rank()) {
					prev_node = current_node;
					current_node = current_node->right_sibling;
				}
				else { //(new_node->get_rank() <= current_node->get_rank())
					new_node->right_sibling = prev_node->right_sibling;
					prev_node->right_sibling = new_node;
					not_inserted = false;
					break;
				}
			}
			if(not_inserted) {
				prev_node->right_sibling = new_node;
				this->size += 1;
			}
		}
		this->print();
		cout << "merging" << endl;
		this->merge();
	}
}

void LinkedList::insert_child(Node* new_node) {

	if(this->head == NULL) {
		this->head = new_node;
		this->head->right_sibling = NULL;
		this->size += 1;
	}
	else {
		new_node->right_sibling = this->head;
		this->head = new_node;
		this->size += 1;
	}
	this->merge();
}

void LinkedList::merge() {
	Node* prev_node = NULL;
	Node* current_node = NULL;
	Node* next_node = NULL;

	while(this->head->right_sibling != NULL && this->head->get_rank() == this->head->right_sibling->get_rank()) {
		current_node = this->head;
		next_node = this->head->right_sibling;
		if(current_node->get_key() <= next_node->get_key()) {
			current_node->right_sibling = next_node->right_sibling;
			// next_node->parent = current_node;
			current_node->add_child(next_node);
		}
		else {	// current_node->get_key() > next_node->get_key()
			this->head = next_node;
			// current_node->parent = next_node;
			next_node->add_child(current_node);
		}

	}

	if(this->head->right_sibling != NULL) {
		prev_node = this->head;
		current_node = this->head->right_sibling;

		while(current_node->right_sibling != NULL) {
			next_node = current_node->right_sibling;
			if(current_node->get_rank() == next_node->get_rank()) {

				if(current_node->get_key() < next_node->get_key()) {
					current_node->right_sibling = next_node->right_sibling;
					// next_node->parent = current_node;
					current_node->add_child(next_node);

					// prev_node = prev_node;
					// current_node = current_node;
				}
				else { // current_node->get_key() >= next_node->get_key()
					prev_node->right_sibling = next_node;
					// current_node->parent = next_node;
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