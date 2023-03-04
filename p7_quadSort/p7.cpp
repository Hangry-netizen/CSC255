/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 7
*/

#include <iostream>

#include "p7.h"

using namespace std;

//******************************************************************************
// Joseph Song & Queena Lee
intList::intList(int listCapacity) {
    // initialize object
    a = new int[listCapacity];
    this -> listCapacity  = listCapacity;
    listSize = 0;
}

//******************************************************************************
// Joseph Song & Queena Lee
intList::~intList() {
    if (a != 0) {
        //if array exists, delete the dynamically allocated array
        delete[] a;
        a = NULL;
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
bool intList::insert(int key) {
    bool rc = listCapacity > listSize;

    //if list has capacity, 
    //move values at the given index and after to the right
    if (rc) {
        for (int i = listSize; i > 0; i--) {
            a[i] = a[i-1];
        }

        //insert the given key at the beginning of the list
        //and increment listSize
        a[0] = key;
        listSize ++;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool intList::add(int key) {
    bool rc = listCapacity > listSize;

    //if list has capacity
    //insert the given key at the end of the list & increment listSize
    if (rc) {
        a[listSize] = key;
        listSize ++;
    }
    
    return rc;
};

//******************************************************************************
// Joseph Song & Queena Lee
bool intList::insertAt(int index, int key) {
    bool rc = (index >= 0) && (index <= listSize);
    
    //if list has capacity
    //move all items at the index to the right
    //starting from the last item at the end of the list
    if (rc) {
        for (int i = listSize; i > index; i--) {
            a[i] = a[i-1];
        }
        //insert new key at the given index & increment listSize
        a[index] = key;
        listSize ++;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool intList::deleteAt(int index, int &key) {
    bool rc = (index >= 0) && (index <= listSize);

    //if index exists within the list range
    //set "key" to the value of the item at the given index
    if (rc) {
        key = a[index];
        listSize--;

        //shift entries right of the index to the left
        for (int i = index; i < listSize; i++) {
            a[i] = a[i+1];
        }
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
void intList::clear() {
    // cause the list to be emptied
    listSize = 0;
}

//******************************************************************************
// Joseph Song & Queena Lee
void intList::printIt(int n) const {
    // for each entry in a, print its index and value
    if (n > listSize) {
        n = listSize;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "At pos " << i << " there is " << a[i] << "\n";
    }

    if (n < listSize) {
        std::cout << "At pos " << listSize-1 << " there is " << a[listSize-1] << "\n";
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
int intList::getIndex(int key) const {
    int rc = -1;

    //if key exists in list, return the index of the key given
    //otherwise, return -1
    for (int i = 0; i < listSize; i++) {
        if (key == a[i]) {
            rc = i;
            break;
        } 
    }


    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool intList::readAt(int index, int &key) const {
    bool rc = false;

    if ((index >= 0) && (index <= listSize)) {
        //if index exists in a
        //return the value stored in the index
        //otherwise, return -1
        key = a[index];
        rc = true;
        
    }
    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
int intList::count() const {
    //returns the number of entries in the list
    return listSize;
}

//******************************************************************************
// Joseph Song & Queena Lee
int intList::capacity() const {
    //returns the capacity of the list
    return listCapacity;
}

//******************************************************************************
// Joseph Song & Queena Lee
void swap(int *x, int *y) {
    //swap two given integers
    int temp = *x;
    *x = *y;
    *y = temp;
}

//******************************************************************************
// Joseph Song & Queena Lee
void intList::bubbleSort() {
    //sort the list using bubble sort
    for (int limit = listSize-1; limit > 0; limit--) {
        //within the limit of the list, sort the list
        bool isSwapped = false;
        for(int i = 0; i < limit; i++) {
            //for each entry within limit
            //if i is larger than its right, swap them
            //until i is smaller than its right or i is at the end of the limit
            if (a[i] > a[i+1]) {
                swap(&a[i],&a[i+1]);
                isSwapped = true;
            }
        }
        if (!isSwapped) {
            //if no swap has been made in a stage, the list is already in order
            break;
        }
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
void intList::selectionSort() {
    //sort the list using selection sort
    for (int limit = 0; limit < listSize-1; limit++) {
        // wihtin the limit of the list, sort the list
        int min = limit;
        for (int i = limit + 1; i < listSize; i++) {
            //find the min value to the right of limit
            if (a[i] < a[min]) {
                min = i;
            }
        }
        if (limit != min) {
            //set the min value found at each stage to the limit index
            a[limit] = a[min];
        }
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
void intList::insertionSort() {
    //sort the list using insertion sort
    for (int limit = 1; limit < listSize; limit ++) {
        //within the limit of the list, sort the list
        int save = a[limit];
        int i;
        for (i = limit; i >= 0; i--) {
            //if saved value is smaller than it's left, keep going left
            //moving each value that is compared one place to the right
            //until saved value is larger than its left
            if (save >= a[i-1]) {
                break;
            }
            a[i] = a[i-1];
        }
        //when saved value is larger than its left place saved value there
        a[i] = save;
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
bool intList::isSorted() const {
    //returns true if list is sorted in ascending order
    //otherwise, return false
    bool rc = true;

    for (int i = 0; i < listSize-1; i++) {
        //for each entry in list, determine if list is in ascending order
        if (a[i] > a[i+1]) {
            rc = false;
            cout << "List is not sorted at " << i << endl;
        }
    }
    return rc;
}