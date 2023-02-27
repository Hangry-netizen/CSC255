/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 6a
*/

#ifndef __P6_H
#define __P6_H

class iPQ {
    private:
        // to hold the integers
        int *values;

        // to record the number of entries in the PQ
        int qCount;

        // to record the size of the array
        int qCapacity;

        // return the parent's index for the given index
        // return 0 if index is 0
        int parent(int index) const;

        // return the index of the left child of the given index
        int left(int index) const;

        // return the index of the left child of the given index
        int right(int index) const;

        // print the tree, level by level
        void printIt(int index, int count) const;

        // swap two integers with each other
        void swap(int *x, int *y);

        // perform the heap bubble-up operation
        void bubbleUp(int index);

        // perform the heap heapify-operation
        void heapify(int index);
    
    public:
        // constructor that causes the object to be initialized
        // with an array of size n, defaulting to 100
        iPQ(int qCapacity = 100);

        // destructor that deletes the array
        ~iPQ();

        // enqueue v into the iPQ; return true for success
        // otherwise, return false if the PQ was already full
        bool enq(int v);

        // return true if the iPQ is not empty
        // also remove and reutnr the maximum value in the PQ
        // return false if the iPQ is empty
        bool deq(int &v);

        // result in the values of the queue being printed 
        // in breadth first order; one line for each level of the tree
        void printIt() const;

        // removes all entries from the iPQ, making it empty
        void clear();

        // return the number of entries in the iPQ
        int count() const;
};

#endif