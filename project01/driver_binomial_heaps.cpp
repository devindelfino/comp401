// driver_binomial_heaps.cpp

#include "BinomialHeap.h"

int main() {
	Node* node1 = new Node(10);
	Node* node2 = new Node(5);
	Node* node3 = new Node(7);

	BinomialHeap heap_1 = BinomialHeap(node1);
	heap_1.display();
	cout << "here" << endl;
	
	heap_1.insert(node2);
	cout << "here" << endl;
	heap_1.display();

	// heap_1.insert(node3);
	// cout << "here" << endl;
	// heap_1.display();
	return 0;
}