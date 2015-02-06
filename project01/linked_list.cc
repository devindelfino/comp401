// LinkedList.cpp

#include "linked_list.h"
#include "node.h"

// -----------------------------------------------------------------------------------------------
LinkedList::LinkedList() {
	this->head = NULL;
	this->size_ = 0;
}

LinkedList::~LinkedList() {
	// delete this->head;
}

void LinkedList::InsertRoot(Node* new_node) {
	new_node->parent_ = NULL;
	new_node->right_sibling_ = NULL;
	if(this->head == NULL) {
		this->head = new_node;
		this->size_ += 1;
	}
	else {
		// check new node against the head of the linked list
		if(new_node->get_rank() < this->head->get_rank()) {
			new_node->right_sibling_ = this->head;
			this->head = new_node;
			this->size_ += 1;
		}
		else if((new_node->get_rank() == this->head->get_rank()) && (new_node->get_key() < this->head->get_key())) {
			new_node->right_sibling_ = this->head;
			this->head = new_node;
		}
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
		this->Print();
		// cout << "merging" << endl;
		this->Merge();
	}
}

void LinkedList::InsertChild(Node* new_node) {

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
	Node* prev_node = NULL;
	Node* current_node = NULL;
	Node* next_node = NULL;

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

	if(this->head->right_sibling_ != NULL) {
		prev_node = this->head;
		current_node = this->head->right_sibling_;

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
	this->UpdateSize();
}

int LinkedList::GetMinimum() {

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
	return this->size_;
}

void LinkedList::Print() {
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
// -----------------------------------------------------------------------------------------------