Project 01: Binomial Heap
==========================
*Devin Delfino*

Description
-----------


Documentation
-------------

###Functionality

This repository contains an implementation of a Binomial Heap that stores integers. The implementation contains the following functions:
* *insert* - Inserts a new job into the heap
* *load_data* - Creates a Binomial Heap of integers from a text file
* *delete_min* - Deletes the node with the minimum key
* *decrease_key* - Decreases the key of a node
* *join* - Joins two Binomial Heaps into one
* *is_empty* - Indicates whether or not the heap is empty
* *find_min* - Finds the node with the lowest key


###Running the program

To compile code...

	make BinomialHeap

To run executable...

	./BinomialHeap

To remove all .o files

	make clean

Complexity Analysis
-------------------

Contents
--------
The project01 directory contains the following files:

In the *project01/* directory:
* *Node.h* - Header file for the Node class
* *Node.cpp* - Implementation of the Node class
* *LinkedList.h* - Header file for the LinkedList class
* *LinkedList.cpp* - Implementation of the LinkedList class
* *BinomialHeap.h* - Header file for the BinomialHeap class
* *BinomialHeap.cpp* - Implementation of the BinomialHeap class
* *Makefile* - Defines the g++ compiling command for easy use

In the *data/* directory:
* *data_file_creator.cpp* - Creates a file of integers for the BinomialHeap class 
* *data10* - Text file containing 10 random integers
* *data100* - Text file containing 100 random integers
* *data10000* - Text file containing 10000 random integers


References
----------
1 [Binomial Heaps](http://www.cs.princeton.edu/~wayne/kleinberg-tardos/pdf/BinomialHeaps.pdf)
2 [Google C++ Style Guide](http://google-styleguide.googlecode.com/svn/trunk/cppguide.html)