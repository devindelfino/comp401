Project 03: The Sieve of Eratosthenes
=====================================
*Devin Delfino*

Description
-----------


Documentation
-------------

#####Usage


#####Functionality


#####Running the program


Complexity Analysis
-------------------


Contents
--------
The project03 directory contains the following files:

In the *project03/* directory:


Parallel Algorithm Design (Reference 1, Chapter 3)
--------------------------------------------------
* The task/channel model represetns a parallel computation as a set of tass that may interact with each other by sending messages through channels
* A task is a program, its local memory, and a collection of I/O ports
* A channel is a message queue that connects one task's output port with another task's input port
* Binomial trees are the most common communication pattern in parallel algorithm design

Foster's Design Methodology
-------------------

1. Partitioning

* def: the porcess of dividing the computation and the data into pieces
* domain decomposition is the parallel algorithm design approach in which we first divide the data into pieces and then determine how to associate computations with the data (it is best to maximize primitive tasks)
* functional decomposition is the strategy in which we first divide the computation into pieces nd then determine how to associate data items with the individual computations
* checklist: Page 67
 
2. Communication

* local communication - when a task needs values from a small number of other tasks in order to perform a computation, we create channels from the tasks supplying data to the task consuming the data
* global communication - when a significant number of the primitive tasks must contribute data in order to perform a computation
* Minimize parallel overhead is very important
* Checklist: commun. operations are balanced among tasks, each task communicates iwth only a small number of neighbors, task can perform their communications and computation concurrently

3. Agglomeration

* def: the process of gropuing tasks into larger tasks in order to improve perforamce or simplify programming. 
* agglomeration lowers communication overhead
* increasing locality of the parallel algorithm is agglomerateing primitive tasks that communicate with each other, resulting in communication between them is eliminated
* can also gropu together sending and receiving tasks, reducing number of messages being sent
* secondary goal is to maintain scalability of the design so it can be later applied to a computer with more processors
* checklist: pg 69

4. Mapping

* def: process of assigning tasks to processors
* Processor utilization is the average percentage of time the system's procesors are actively executing tasks necessary for the solution of the problem

Message-Passing Programming (Reference 1, Chapter 4)
--------------------------------------------------
* rank of a process is its position in the overall order
MPI Functions
-------------
* MPI_Init() - Initialize MPI
* MPI_Comm_rank() - determines a process's ID number
* MPI_Comm_size() - finds the number of processes
* MPI_Reduce() - performs a reduction operation
* MPI_Finalize() - shuts down MPI
* MPI_Barrier() - performs a barrier synchronization
* MPI_Wtime() - determines the time
* MPI_Wtick() - finds the accuracy of the timer

The Sieve of Eratosthenes (Reference 1, Chapter 5)
--------------------------------------------------

References
----------
1. Parallel Programming in C with MPI and OpenMP by Michael J. Quinn