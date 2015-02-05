// driver_binomial_heaps.cpp

#include "BinomialHeap.h"

int main() {
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

	
	return 0;
}