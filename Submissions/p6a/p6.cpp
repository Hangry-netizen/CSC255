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
    //initialize values, qCount, and qCapacity with a default of 100
    values = new int[qCapacity];
    qCount = 0;
    this->qCapacity = qCapacity;
}

//******************************************************************************
// Joseph Song & Queena Lee
iPQ::~iPQ() {
    if (values) {
        //if array exists, delete the dynamically allocated array
        delete[] values;
        values = NULL;
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
int iPQ::parent(int index) const {
    int rc = 0;

    if (index) {
        rc = (index-1) / 2;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
int iPQ::left(int index) const {
    return (2*index) + 1;
}

//******************************************************************************
// Joseph Song & Queena Lee
int iPQ::right(int index) const {
    return 2*(index + 1);
}

//******************************************************************************
// Joseph Song & Queena Lee
void iPQ::printIt(int index, int count) const {
    int start, stop;
    start = count - 1;
    stop = start + count;

    if (start < qCount) {
        if (stop > qCount) {
            stop = qCount;
        }

        cout << "Level [" << index << "] -> ";
        for (int i = start; i < stop; i++) {
            cout << values[i] << " ";
        }
        cout << endl;
        printIt(index + 1, count << 1);
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
void iPQ::swap(int *x, int *y) {
    //swap two integers with each other
    int temp = *x;
    *x = *y;
    *y = temp;
}

//******************************************************************************
// Joseph Song & Queena Lee
void iPQ::bubbleUp(int index) {
    //perform the heap bubble-up operation
    if (index) {
        int p = parent(index);
        if (values[index] > values[p]) {
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
        int larger = index;
        int l = left(index);

        if (l < qCount) {
            if (values[l] > values[larger]) {
                larger = l;
            }
            int r = right(index);
            if (r < qCount) {
                if (values[r] > values[larger]) {
                    larger = r;
                }
            }
        } 
        if (index != larger) {
            swap(&values[index], &values[larger]);
            heapify(larger);
        }  
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
bool iPQ::enq(int v) {
    bool rc = qCount < qCapacity;

    if (rc) {
        values[qCount] = v;
        bubbleUp(qCount);
        qCount++;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool iPQ::deq(int &v) {
    bool rc = qCount > 0;

    if (rc) {
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
    printIt(0,1);
}

//******************************************************************************
// Joseph Song & Queena Lee
void iPQ::clear() {
    qCount = 0;
}

//******************************************************************************
// Joseph Song & Queena Lee
int iPQ::count() const {
    return qCount;
}