// BinomialHeap.cpp

#include "BinomialHeap.h"

BinomialHeap::BinomialHeap() {

}

BinomialHeap::BinomialHeap(Node* new_node) {
	this->root_list.insert_child(new_node);
}

BinomialHeap::~BinomialHeap() {
	//
}

void BinomialHeap::insert(Node* new_node) {
	cout << "entering BH::insert" << endl;
	BinomialHeap temp_heap = BinomialHeap(new_node);
	this->join(temp_heap);
	cout << "exiting BH::insert" << endl;
}

void BinomialHeap::join(BinomialHeap b_heap) {
	cout << "entering BH::join" << endl;
	Node* temp_node = b_heap.root_list.head;
	Node* iterator = b_heap.root_list.head;
	// temp_node->print();
	while(iterator != NULL) {
		temp_node = iterator;
		iterator = iterator->right_sibling;
		cout << "boom" << endl;
		this->root_list.insert_root(temp_node);
	}
	cout << "exiting BH::join" << endl;
}

// Node* BinomialHeap::delete_min() {      need to deal with head pointer
// 	int min = this->find_min();
// 	Node* deleted_node = NULL;

// 	BinomialHeap b_heap = BinomialHeap();

// 	Node* temp_node = b_heap.root_list.head;
// 	Node* prev_node = NULL;
// 	while(temp_node != NULL) {
// 		if(temp_node->get_key() == min) {
// 			deleted_node = temp_node;
// 			break;
// 		}
// 	}
// 	return deleted_node;
// }

bool BinomialHeap::is_empty() {
	if(this->root_list.head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void BinomialHeap::load_data(string file_name) {
	
}

int BinomialHeap::find_min() {
	return this->root_list.get_min();
}

void BinomialHeap::display() {
	cout << "==========================================" << endl;
	cout << "Root List: ";
	this->root_list.print();
	cout << endl;

	Node* temp_node = this->root_list.head;
	while(temp_node != NULL) {
		cout << "==========================================" << endl;
		this->print_out(temp_node);
		temp_node = temp_node->right_sibling;
	}
	cout << "==========================================" << endl;
}

void BinomialHeap::print_out(Node* n) {
	cout << "--------------------------------------------" << endl;
	n->print();

	Node* temp_node = n->children.head;
	while(temp_node != NULL) {
		this->print_out(temp_node);
		temp_node = temp_node->right_sibling;
	}
	cout << "--------------------------------------------" << endl;
}

