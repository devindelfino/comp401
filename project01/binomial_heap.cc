// BinomialHeap.cpp

#include "binomial_heap.h"

BinomialHeap::BinomialHeap() {

}

BinomialHeap::BinomialHeap(Node* new_node) {
	this->root_list.insert_root(new_node);
}

BinomialHeap::~BinomialHeap() {
	//
}

void BinomialHeap::insert(Node* new_node) {
	new_node->parent = NULL;
	new_node->right_sibling = NULL;
	BinomialHeap temp_heap = BinomialHeap(new_node);
	this->join(temp_heap);
}

void BinomialHeap::insert(int key) {
	Node* new_node = new Node(key);
	BinomialHeap temp_heap = BinomialHeap(new_node);
	this->join(temp_heap);
}

void BinomialHeap::join(BinomialHeap b_heap) {
	Node* temp_node = NULL;
	Node* iterator = b_heap.root_list.head;
	// temp_node->print();
	while(iterator != NULL) {
		temp_node = iterator;
		iterator = iterator->right_sibling;
		this->root_list.insert_root(temp_node);
	}
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

	cout << "merged heap from children" <<endl;
	merge_heap.display();
	// join the original heap with the new merge_heap containing the children of the deleted node
	this->join(merge_heap);
	cout << "Deleting Node: ";
	deleted_node->print();
	cout << endl;
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
	ifstream fin;

	fin.open(file_name);

	int new_key;
	while(!fin.eof()) {
		fin >> new_key;
		this->insert(new_key);
		cout << new_key << " inserted" <<endl;
	}

	fin.close();
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

	cout << "Decreasing Key of node ";
	handle->print();
	cout << " from " << handle->get_key() << " to " << new_key << endl;
	handle->update_key(new_key);
}

void BinomialHeap::delete_node(Node* handle) {
	cout << "Deleting node ";
	handle->print();
	this->decrease_key(handle, -999999);
	this->delete_min();
}

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
