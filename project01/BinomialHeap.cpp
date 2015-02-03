// BinomialHeap.cpp

#include "BinomialHeap.h"

BinomialHeap::BinomialHeap() {
	this->size = 0;
}

BinomialHeap::BinomialHeap(int key) {
	Node* new_node = new Node(key);

	this->root_list.insert(new_node);
	this->size = 1;
}

BinomialHeap::~BinomialHeap() {
	//
}

void BinomialHeap::insert(int key) {
	BinomialHeap temp_heap = new BinomialHeap(key);
	this->join(temp_heap);
}

void BinomialHeap::join(BinomialHeap b_heap) {
	Node* b_heap_it = b_heap.head;
	

	this->size += b_heap.get_size();
}

Node* BinomialHeap::delete_min() {

	this->size -= 1;
}

bool BinomialHeap::is_empty() {
	if(this->size == 0) {
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

int BinomialHeap::get_size() {
	return this->size;
}