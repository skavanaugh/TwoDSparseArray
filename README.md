csci333-TwoDArray
=================

Just a few notes about the project:

After coding part of the sparse array implementation, I decided to change my row and column arrays from Node<T>* to LinkedList<T>*.  I created a lightweight LinkedList class with a head and numElements and a handful of basic methods like getHead, setHead, getSize, setSize and isEmpty. This design decision made the implementation slightly easier than it was with an array of Node pointers.  Additionally, the majority of the heavy lifing within Sparse Array implementation of the TwoDArray class was performed by a couple of helper methods.  The first, findNode returns a Node<T>* to the Node<T> at(r,c).  The other helper, getNodes, a boolean, calculates whether there is a Node<T> at (r,c) and where the previousLeft Node<T>* and previousUp Node<T>* either are or would be for a given row and column.  These helper methods greatly simplified the implementation of access, insert and delete within the TwoDArray class.  One other detail that made debugging and testing easier was adding assertions to the Node class in all of the getNext and setNext methods.

I did some basic memory error detection tests on all of my implementations using a utility called Valgrind. I found memory leaks in my sparse array and was able to pinpoint and fix them without too much trouble.  Check it out at valgrind.org .  apt-get install valgrind .  Then add -g to the compiler flags and from the command line type valgrind --log-file=filename --leak-check=yes --tool=memcheck ./binaryname .  The log file provides a detailed report.

I implemented the vector based TwoDArray in two different ways, one declaring theVector, a vector of vectors on the stack as a private member variable, and the other with a pointer to a vector of vectors on the heap.  Both of these, according to Valgrind, are currently memory leak free, as are the array based implementation and the sparse array.

Typing make in the project root directory causes the appropriate object files and executables to be created.  Without the sparse array implementation, I used the Array header in the include directory which worked smoothly, but after finishing the sparse array, I had difficulties with the sparse array using the array based header.  I changed over to the sparse array based header and everything worked well but at this point I think I needed the LinkedList.h and Node.h headers as well.  The single testing file can include the TwoDArray.h file in the src/Sparse2D directory or it can be copied over to the include directory along with LinkedList.h and Node.h.  I'm not sure about this, but perhaps the reason for needing to use the sparse array header file is that I used private helper methods in this implementation.  In the previous Queue project, I could only compile everything successfully using the Array based header, where I used private helper methods.  Perhaps there is some trick needed in order to use a header which just publishes the public API when private helper methods are used to implement a class. 
 




