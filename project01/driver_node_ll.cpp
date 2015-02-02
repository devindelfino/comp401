// driver.cpp

#include <iostream>
using namespace std;
#include "Node.h"
#include "LinkedList.h"

int main() {

	LinkedList LL;
	Node* n1 = new Node(8);
	Node* n2 = new Node(5);
	Node* n3 = new Node(7);

	LL.insert(n1);
	LL.insert(n2);
	LL.insert(n3);

	LL.print();

	n1->print();
	n2->print();
	n3->print();

	return 0;
}