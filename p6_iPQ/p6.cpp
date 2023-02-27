/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 6a
*/

#include <iostream>
#include <fstream>

#include "p6.h"

using namespace std;

//******************************************************************************
// Joseph Song & Queena Lee
iPQ::iPQ(int qCapacity) {
    // initialize values, qCount, and qCapacity with a default of 100
    values = new int[qCapacity];
    qCount = 0;
    this->qCapacity = qCapacity;
}

//******************************************************************************
// Joseph Song & Queena Lee
iPQ::~iPQ() {
    if (values) {
        // if array exists, delete the dynamically allocated array
        delete[] values;
        values = NULL;
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
int iPQ::parent(int index) const {
    // return the index of the parent of the given index
    int rc = 0;

    if (index) {
        rc = (index-1) / 2;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
int iPQ::left(int index) const {
    // return the index of the left child of the given index
    return (2*index) + 1;
}

//******************************************************************************
// Joseph Song & Queena Lee
int iPQ::right(int index) const {
    // return the index of the right child of the given index
    return 2*(index + 1);
}

//******************************************************************************
// Joseph Song & Queena Lee
void iPQ::printIt(int index, int count) const {
    int start, stop;
    start = count - 1;
    stop = start + count;

    if (start < qCount) {
        // if starting index in within queue
        if (stop > qCount) {
            // make sure stopping index is within queue
            stop = qCount;
        }

        // print tree level and entries at that level
        cout << "Level [" << index << "] -> ";
        for (int i = start; i < stop; i++) {
            cout << values[i] << " ";
        }
        cout << endl;

        // recurse function until each level and entry have been printed
        printIt(index + 1, count << 1);
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
void iPQ::swap(int *x, int *y) {
    // swap two integers with each other
    int temp = *x;
    *x = *y;
    *y = temp;
}

//******************************************************************************
// Joseph Song & Queena Lee
void iPQ::bubbleUp(int index) {
    // perform the heap bubble-up operation
    if (index) {
        // get parent's index
        int p = parent(index);

        if (values[index] > values[p]) {
            // if the value at index is larger than its parent's, swap them
            // recurse function until tree satisfies the properties of a maxHeap 
            swap(&values[index], &values[p]);
            bubbleUp(p);
        }
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
void iPQ::heapify(int index) {
    // perform the heap heapify operation
    if (qCount) {
        // if queue exists, get the larger entry between index and its children
        int larger = index;
        int l = left(index);
        int r = right(index);

        if (l < qCount) {
            if (values[l] > values[larger]) {
                larger = l;
            }
            if (r < qCount) {
                if (values[r] > values[larger]) {
                    larger = r;
                }
            }
        } 

        // if index has a child that is larger than itself and swap them
        // recurse function until tree satisfies the properties of a maxHeap
        if (index != larger) {
            swap(&values[index], &values[larger]);
            heapify(larger);
        }  
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
bool iPQ::enq(int v) {
    // add given integer to the queue
    // return true if successful; otherwise, return false
    bool rc = qCount < qCapacity;

    if (rc) {
        // if queue has capacity, add given integer to the queue
        // bubbleUp to ensure tree satisfies the properties of a maxHeap
        // increment queue count
        values[qCount] = v;
        bubbleUp(qCount);
        qCount++;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool iPQ::deq(int &v) {
    // remove the first entry from the queue
    // if successful, return true along with the value of the removed entry
    // otherwise, return false
    bool rc = qCount > 0;

    if (rc) {
        // if queue is not empty, remove first entry, decrement queue count
        // heapify tree to ensure tree satisfies the properties of a maxHeap
        v = values[0];
        qCount--;
        values[0] = values[qCount];
        heapify(0);
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
void iPQ::printIt() const {
    // call recursion function to print all entries in the queue
    printIt(0,1);
}

//******************************************************************************
// Joseph Song & Queena Lee
void iPQ::clear() {
    // empty queue list
    qCount = 0;
}

//******************************************************************************
// Joseph Song & Queena Lee
int iPQ::count() const {
    // return queue count
    return qCount;
}