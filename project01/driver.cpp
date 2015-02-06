// driver.cpp

#include "binomial_heap.h"

int main() {
	cout << "---------------------------------------------------" << endl;
	cout << "INSERTING INTEGERS INTO A BINOMIAL HEAP (step by step)" << endl;
	cout << "---------------------------------------------------" << endl;

	Node* node1 = new Node(10);
	Node* node2 = new Node(5);
	Node* node3 = new Node(7);
	Node* node4 = new Node(20);
	Node* node5 = new Node(4);
	Node* node6 = new Node(16);
	Node* node7 = new Node(10);
	Node* node8 = new Node(10);
	Node* node9 = new Node(1);
	Node* nodea = new Node(9);

	BinomialHeap heap_1 = BinomialHeap(node1);
	heap_1.display();

	heap_1.insert(node2);
	heap_1.display();

	heap_1.insert(node3);
	heap_1.display();

	heap_1.insert(node4);
	heap_1.display();

	heap_1.insert(node5);
	heap_1.display();

	heap_1.insert(node6);
	heap_1.display();

	heap_1.insert(node7);
	heap_1.display();

	heap_1.insert(node8);
	heap_1.display();

	heap_1.insert(node9);
	heap_1.display();

	heap_1.insert(nodea);
	heap_1.display();


	cout << "---------------------------------------------------" << endl;
	cout << "SEARCHING FOR KEYS" << endl;
	cout << "---------------------------------------------------" << endl;

	int query = 67;
	Node* found = heap_1.search(query);
	if(found == NULL) {
		cout << query << " not found." << endl;
	}
	else {
		cout << query << " found!" << endl;
		found->print();
	}

	query = 7;
	found = heap_1.search(query);
	if(found == NULL) {
		cout << query << " not found." << endl;
	}
	else {
		cout << query << " found!" << endl;
		found->print();
	}

	cout << "---------------------------------------------------" << endl;
	cout << "DECREASING A KEY" << endl;
	cout << "---------------------------------------------------" << endl;

	heap_1.decrease_key(found, 3);
	heap_1.display();

	cout << "---------------------------------------------------" << endl;
	cout << "DELETING A NODE" << endl;
	cout << "---------------------------------------------------" << endl;

	Node* node_to_delete = heap_1.search(5);
	heap_1.delete_node(node_to_delete);

	cout << "---------------------------------------------------" << endl;
	cout << "CREATING BINOMIAL HEAP FROM TEXT FILE" << endl;
	cout << "---------------------------------------------------" << endl;

	BinomialHeap heap_from_file = BinomialHeap();
	heap_from_file.load_data("./data/data10.dat");

	heap_from_file.display();

	cout << "---------------------------------------------------" << endl;
	cout << "DELETING MINIMUM NODE" << endl;
	cout << "---------------------------------------------------" << endl;

	heap_from_file.delete_min();
	heap_from_file.display();
	heap_from_file.delete_min();
	heap_from_file.display();
	heap_from_file.delete_min();
	heap_from_file.display();
	heap_from_file.delete_min();
	heap_from_file.display();

	return 0;
}