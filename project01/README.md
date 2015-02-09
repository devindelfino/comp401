Project 01: Binomial Heap
==========================
*Devin Delfino*

Description
-----------
A binomial heap is a data structure that is comprised of a collection of trees that satisfy a heap property. This means that for any node in the heap, its key will always be less than or equal to the keys of its children (min heap). Because of this, binomial heaps are a type of implementation of a priority queue, where the key of each node indicates some sort of order or priority. After each new node is inserted into the binomial heap, two trees are merged together if their two root nodes share the same rank/order (the number of children nodes it has). Each binomial tree in the binomial heap has another property where if it has a rank of k (k children), then each child has a rank 0, 1, ..., k - 2, k - 1 from right to left. This leads to the fact that a binomial tree of order k (root node has order k) has 2^k nodes. The unique structure of the binomial trees allow for relatively simple merging of two trees whose roots have the same order k , where the root with the larger key becomes a child of the root with the smaller key, creating a binomial tree whose root is order k+1.

The structure of a binomial heap with n nodes can be determined by the binary representation of n. For example, since 14 base 10 = 1110 base 2 which can be represented as 2^3 + 2^2 + 2^1, a binomial tree with n nodes will consist of a three binomial trees with orders 1, 2, and 3 (from left to right). This ensures that any binomial heap contains less than or equal to log(n) + 1 binomial trees. In other words, if a binomial heap contains 14 nodes, since 14 can be represented by 4 bits, all of the nodes can be stored in at most 4 binomial trees.

Documentation
-------------

#####Usage

To utilize this code in other code: 

1. Place the files *Node.h*, *Node.cpp*, *LinkedList.h*, *LinkedList.cpp*, *BinomialHeap.h*, and *BinomialHeap.cpp* in the same directory as the other code.
2. Include the following line of code at the top of the main *.cpp* file of the code.

		#include "binomial_heap.h"

3. When compiling, make sure to include *Node.cpp*, *LinkedList.cpp*, and *BinomialHeap.cpp* in addition to the rest of the *.cpp* files needed.

#####Functionality

This repository contains an implementation of a Binomial Heap that stores integers. The implementation contains the following functions:
* *Insert* - Inserts a new job into the heap
* *LoadData* - Creates a Binomial Heap of integers from a text file
* *DeleteMinimum* - Deletes the node with the minimum key_
* *DecreaseKey* - Decreases the key_ of a specific node
* *Join* - Joins a second binomial heap into an existing one
* *IsEmpty* - Indicates whether or not the heap is empty
* *FindMinimum* - Finds the minimum key_ in the heap


#####Running the program

To compile code...

	make binomial_heap

To run executable...

	./binomial_heap

To remove all .o files

	make clean

Complexity Analysis
-------------------

#####Join - O(log n)

Consider merging two binomial heaps into one, where the larger of the two heaps has n nodes. In order to insert each binomial tree from one heap into the other, it requires iterating through the roots of both heaps in order to find where to merge binomial trees of certain order. Again, this takes log(n) time.

#####Insert - O(log n)

This operation consists of creating a new binomial heap of a single node, then joining it with the original heap. Therefore, it is the same time complexity as the join operation.

#####Delete Minimum - O(log n)

After deleting the minimum node, its children are made into a new binomial heap and then merged back into the original heap. Since the minimum node is one of the roots of the binomial trees, and at most the root has order log(n), then the new binomial heap will have less than or equal to log(n) binomial trees that must be merged into the original. This is accomplished using the Join operation, which is O(log n).

#####Decrease Key - O(log n)

Since at most, the order of one of the heap's binomial trees is log(n), the height of the tree is also less than or equal to log(n). The worst case if if we wish to decrease the key of the leaf node of a log(n)-ordered binomial tree so it is the new minimum key, triggering a swap with each parent node's key until the new minimum is at the root. This will take log(n) swaps because of the maximum height of log(n) of a binomial tree in a binomial heap.

#####Find Minimum Key - O(log n)

Because of the minimum heap property where the key of a node is always less than or equal to the keys of its children, the minimum key of each binomial tree within the heap will always be the root of the tree. Since a binomial heap with n nodes has at most floor(log(n)) + 1 binomial trees, the minimum key in the heap can be found by iterating through each root of the floor(log(n)) + 1 binomial trees, keeping track of the minimum. This operation can be performed in O(log n) time.



Contents
--------
The project01 directory contains the following files:

In the *project01/* directory:
* *node.h* - Header file for the Node class
* *node.cc* - Implementation of the Node class
* *linked_list.h* - Header file for the LinkedList class
* *linked_list.cc* - Implementation of the LinkedList class
* *binomial_heap.h* - Header file for the BinomialHeap class
* *binomial_heap.cc* - Implementation of the BinomialHeap class
* *Makefile* - Defines the g++ compiling command for easy use

In the *data/* directory:
* *data_file_creator.cc* - Creates a file of integers for the BinomialHeap class 
* *data10* - Text file containing 10 random integers
* *data100* - Text file containing 100 random integers
* *data10000* - Text file containing 10000 random integers


References
----------
1. [Priority Queues](http://www.cs.princeton.edu/~wayne/kleinberg-tardos/pdf/BinomialHeaps.pdf)
2. [Binomial Heaps](http://en.wikipedia.org/wiki/Binomial_heap)
3. [Binomial Queue Visualization](http://www.cs.usfca.edu/~galles/visualization/BinomialQueue.html)
4. [Google C++ Style Guide](http://google-styleguide.googlecode.com/svn/trunk/cppguide.html)