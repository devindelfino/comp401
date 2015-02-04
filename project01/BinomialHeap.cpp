// BinomialHeap.cpp

#include "BinomialHeap.h"

BinomialHeap::BinomialHeap() {

}

BinomialHeap::BinomialHeap(int new_node) {
	this->root_list.insert(new_node);
}

BinomialHeap::~BinomialHeap() {
	//
}

void BinomialHeap::insert(int new_node) {
	BinomialHeap temp_heap = BinomialHeap(new_node);
	this->join(temp_heap);
}

void BinomialHeap::join(BinomialHeap b_heap) {
	Node* temp_node = b_heap.root_list.head;
	while(temp_node != NULL) {
		this->root_list.insert(temp_node);
		temp_node = temp_node->right_sibling;
	}
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