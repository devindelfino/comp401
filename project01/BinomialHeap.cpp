// BinomialHeap.cpp

#include "BinomialHeap.h"

BinomialHeap::BinomialHeap() {

}

BinomialHeap::BinomialHeap(int key) {
	Node* new_node = new Node(key);

	this->root_list.insert(new_node);
}

BinomialHeap::~BinomialHeap() {
	//
}

void BinomialHeap::insert(int key) {
	BinomialHeap temp_heap = BinomialHeap(key);
	this->join(temp_heap);
}

void BinomialHeap::join(BinomialHeap b_heap) {
	Node* b_heap_it = b_heap.root_list.head;
}

Node* BinomialHeap::delete_min() {

	
}

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