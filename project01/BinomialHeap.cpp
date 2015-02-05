// BinomialHeap.cpp

#include "BinomialHeap.h"

BinomialHeap::BinomialHeap() {

}

BinomialHeap::BinomialHeap(Node* new_node) {
	this->root_list.insert_root(new_node);
}

BinomialHeap::~BinomialHeap() {
	//
}

void BinomialHeap::insert(Node* new_node) {
	cout << "entering BH::insert" << endl;
	new_node->parent = NULL;
	new_node->right_sibling = NULL;
	BinomialHeap temp_heap = BinomialHeap(new_node);
	this->join(temp_heap);
	cout << "exiting BH::insert" << endl;
}

void BinomialHeap::join(BinomialHeap b_heap) {
	cout << "entering BH::join" << endl;
	Node* temp_node = NULL;
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

Node* BinomialHeap::delete_min() {
	int min = this->find_min();
	Node* deleted_node = NULL;

	// find and extract the minimum node from root_list
	Node* current_node = this->root_list.head;
	Node* prev_node = NULL;

	while(current_node != NULL) {
		if(current_node->get_key() == min) {
			deleted_node = current_node;
			if(prev_node == NULL) {
				// the minimum node is the head of the root list
				this->root_list.head = deleted_node->right_sibling;
			}
			else {
				prev_node->right_sibling = deleted_node->right_sibling;
			}
			break;
		}
		else {
			prev_node = current_node;
			current_node = current_node->right_sibling;
		}
	}

	// insert the children of the deleted node into a new heap
	BinomialHeap merge_heap = BinomialHeap();

	Node* temp_node = NULL;
	Node* iterator = deleted_node->children.head;
	while(iterator != NULL) {
		temp_node = iterator;
		iterator = iterator->right_sibling;
		merge_heap.insert(temp_node);
	}

	// join the original heap with the new merge_heap containing the children of the deleted node
	this->join(merge_heap);

	return deleted_node;
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

void BinomialHeap::display() {
	cout << "==========================================" << endl;
	cout << "Root List: ";
	this->root_list.print();
	cout << endl;

	Node* temp_node = this->root_list.head;
	while(temp_node != NULL) {
		cout << "ROOT ==========================================" << endl;
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

void BinomialHeap::decrease_key(Node* handle, int new_key) {
	handle->update_key(new_key);

	//handle restructuring of heap
}

// Node* BinomialHeap::delete(Node* handle) {
// 	this->decrease_key(handle, -999999);
// 	this->delete_min();
// }

Node* BinomialHeap::search(int key_query) {
	Node* handle = NULL;
	Node* temp_node = this->root_list.head;
	while(temp_node != NULL) {
		handle = this->search_subtree(key_query, temp_node);
		if(handle == NULL) {
			temp_node = temp_node->right_sibling;
		}
		else {
			break;
		}
	}
	return handle;
}

Node* BinomialHeap::search_subtree(int key_query, Node* sub_root) {
	Node* handle = NULL;
	if(sub_root->get_key() == key_query) {
		handle = sub_root;
	}
	else {
		Node* temp_node = sub_root->children.head;
		while(temp_node != NULL) {
			handle = this->search_subtree(key_query, temp_node);
			if(handle == NULL) {
				temp_node = temp_node->right_sibling;
			}
			else {
				break;
			}
		}
	}
	return handle;
}
