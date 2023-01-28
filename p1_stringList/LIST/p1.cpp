/*
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 1b
*/

#include <iostream>

#include "p1.h"

using namespace std;

//******************************************************************************

stringList::stringList(int listCapacity) {
    a = new std::string[listCapacity];
    listCapacity = listCapacity;
    listSize = 0;
}

//******************************************************************************

stringList::~stringList() {
    if (a != 0) {
        delete[] a;
        a = NULL;
    }
}

//******************************************************************************

bool stringList::insert(std::string text) {
    bool rc = listCapacity > listSize;

    //if list has capacity, 
    //move values at the given index and after to the right
    if (rc) {
        for (int i = listSize; i > 0; i--) {
            a[i] = a[i-1];
        }

        //insert the given text at the beginning of the list
        //and increment listSize
        a[0] = text;
        listSize ++;
    }

    return rc;
}

//******************************************************************************

bool stringList::add(std::string text) {
    bool rc = listCapacity > listSize;

    //if list has capacity
    //insert the given text at the end of the list & increment listSize
    if (rc) {
        a[listSize] = text;
        listSize ++;
    }
    
    return rc;
};

//******************************************************************************

bool stringList::insertAt(int index, std::string text) {
    bool rc = listCapacity > listSize;
    
    //if list has capacity
    //move all items at the index to the right
    //starting from the last item at the end of the list
    if (rc) {
        for (int i = listSize; i > index; i--) {
            a[i] = a[i-1];
        }
        //insert new text at the given index & increment listSize
        a[index] = text;
        listSize ++;
    }

    return rc;
}

//******************************************************************************

bool stringList::deleteAt(int index, std::string &text) {
    bool rc = (!(index < 0)) && (index < listSize);

    //if index exists within the list range
    //set "text" to the value of the item at the given index
    if (rc) {
        text = a[index];
        listSize--;

        //shift entries right of the index to the left
        for (int i = index; i < listSize; i++) {
            a[i] = a[i+1];
        }
    }

    return rc;
}

//******************************************************************************
void stringList::clear() {
    //causes the list to be emptied
    listSize = 0;
}

//******************************************************************************

void stringList::printIt() const {
    // for each entry in a, print its index and value
    for (int i = 0; i < listSize; i++) {
        std::cout << "At pos " << i << " there is " << a[i] << "\n";
    }
}

//******************************************************************************

int stringList::getIndex(std::string text) const {
    int rc = -1;

    if (listSize != 0) {
        //if list is not empty
        //return the index of the text given
        //otherwise, return -1
        for (int i = 0; i < listSize; i++) {
            if (text == a[i]) {
                rc = i;
            } 
        }
    }

    return rc;
}

//******************************************************************************

bool stringList::readAt(int index, std::string &text) const {
    bool rc = false;
    //(!(index < 0)) && (index < listSize);


    if ((!(index < 0)) && (index < listSize)) {
        //if index exists in a
        //return the value stored in the index
        //otherwise, return -1
        text = a[index];
        rc = true;
        
    }
    return rc;
}

//******************************************************************************

int stringList::count() const {
    //returns the number of entries in the list
    return listSize;
}