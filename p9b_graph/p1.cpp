/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 1
*/

#include <iostream>

#include "p1.h"

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

    cout << "printIt with list size: " << n << " capacity = "
    << listCapacity << endl;
    
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
int intList::readAt(int index) const {
    int rc = -1;

    if ((index >= 0) && (index <= listSize)) {
        //if index exists in a
        //return the value stored in the index
        //otherwise, return -1
        rc = a[index];
        
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