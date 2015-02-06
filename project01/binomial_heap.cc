// BinomialHeap.cpp

#include "binomial_heap.h"

BinomialHeap::BinomialHeap() {

}

BinomialHeap::BinomialHeap(Node* new_node) {
	this->root_list_.InsertRoot(new_node);
}

BinomialHeap::~BinomialHeap() {
	//
}

void BinomialHeap::Insert(Node* new_node) {
	new_node->parent_ = NULL;
	new_node->right_sibling_ = NULL;
	BinomialHeap temp_heap = BinomialHeap(new_node);
	this->Join(temp_heap);
}

void BinomialHeap::Insert(int key) {
	Node* new_node = new Node(key);
	BinomialHeap temp_heap = BinomialHeap(new_node);
	this->Join(temp_heap);
}

void BinomialHeap::Join(BinomialHeap b_heap) {
	Node* temp_node = NULL;
	Node* iterator = b_heap.root_list_.head;
	// temp_node->Print();
	while(iterator != NULL) {
		temp_node = iterator;
		iterator = iterator->right_sibling_;
		this->root_list_.InsertRoot(temp_node);
	}
}

Node* BinomialHeap::DeleteMinimum() {
	int min = this->FindMinimum();
	Node* deleted_node = NULL;

	// find and extract the minimum node from root_list_
	Node* current_node = this->root_list_.head;
	Node* prev_node = NULL;

	while(current_node != NULL) {
		if(current_node->get_key() == min) {
			deleted_node = current_node;
			if(prev_node == NULL) {
				// the minimum node is the head of the root list
				this->root_list_.head = deleted_node->right_sibling_;
			}
			else {
				prev_node->right_sibling_ = deleted_node->right_sibling_;
			}
			break;
		}
		else {
			prev_node = current_node;
			current_node = current_node->right_sibling_;
		}
	}

	// Insert the children_ of the deleted node into a new heap
	BinomialHeap Merge_heap = BinomialHeap();

	Node* temp_node = NULL;
	Node* iterator = deleted_node->children_.head;
	while(iterator != NULL) {
		temp_node = iterator;
		iterator = iterator->right_sibling_;
		Merge_heap.Insert(temp_node);
	}

	cout << "Merged heap from children_" <<endl;
	Merge_heap.Display();
	// Join the original heap with the new Merge_heap containing the children_ of the deleted node
	this->Join(Merge_heap);
	cout << "Deleting Node: ";
	deleted_node->Print();
	cout << endl;
	return deleted_node;
}

bool BinomialHeap::IsEmpty() {
	if(this->root_list_.head == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void BinomialHeap::LoadData(string file_name) {
	ifstream fin;

	fin.open(file_name);

	int new_key;
	while(!fin.eof()) {
		fin >> new_key;
		this->Insert(new_key);
		cout << new_key << " Inserted" <<endl;
	}

	fin.close();
}

int BinomialHeap::FindMinimum() {
	return this->root_list_.GetMinimum();
}

void BinomialHeap::Display() {
	cout << "==========================================" << endl;
	cout << "Root List: ";
	this->root_list_.Print();
	cout << endl;

	Node* temp_node = this->root_list_.head;
	while(temp_node != NULL) {
		cout << "ROOT ==========================================" << endl;
		this->PrintOut(temp_node);
		temp_node = temp_node->right_sibling_;
	}
	cout << "==========================================" << endl;
}

void BinomialHeap::PrintOut(Node* n) {
	cout << "--------------------------------------------" << endl;
	n->Print();

	Node* temp_node = n->children_.head;
	while(temp_node != NULL) {
		this->PrintOut(temp_node);
		temp_node = temp_node->right_sibling_;
	}
	cout << "--------------------------------------------" << endl;
}

void BinomialHeap::DecreaseKey(Node* handle, int new_key) {

	cout << "Decreasing key of node ";
	handle->Print();
	cout << " from " << handle->get_key() << " to " << new_key << endl;
	handle->set_key(new_key);
}

void BinomialHeap::DeleteNode(Node* handle) {
	cout << "Deleting node ";
	handle->Print();
	this->DecreaseKey(handle, -999999);
	this->DeleteMinimum();
}

Node* BinomialHeap::Search(int key_query) {
	Node* handle = NULL;
	Node* temp_node = this->root_list_.head;
	while(temp_node != NULL) {
		handle = this->SearchSubTree(key_query, temp_node);
		if(handle == NULL) {
			temp_node = temp_node->right_sibling_;
		}
		else {
			break;
		}
	}
	return handle;
}

Node* BinomialHeap::SearchSubTree(int key_query, Node* sub_root) {
	Node* handle = NULL;
	if(sub_root->get_key() == key_query) {
		handle = sub_root;
	}
	else {
		Node* temp_node = sub_root->children_.head;
		while(temp_node != NULL) {
			handle = this->SearchSubTree(key_query, temp_node);
			if(handle == NULL) {
				temp_node = temp_node->right_sibling_;
			}
			else {
				break;
			}
		}
	}
	return handle;
}
