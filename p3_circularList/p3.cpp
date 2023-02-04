/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 3a
*/

#include <iostream>
#include <fstream>

#include "p3.h"

using namespace std;

//******************************************************************************

cStringList::cStringList(int listCapacity) {
    a = new std::string[listCapacity];
    listCapacity = listCapacity;
    listCount = 0;
    first = last = 0;
}

//******************************************************************************

cStringList::~cStringList() {
    if (a != 0) {
        delete[] a;
        a = NULL;
    }
}

//******************************************************************************

void cStringList::incVal(int &value) {
    value = value + 1;
    value = value % listCapacity;
}

//******************************************************************************

void cStringList::decVal(int &value) {
    value = value - 1;
    if (value < 0) {
        value = listCapacity - 1;
    }
}

//******************************************************************************

bool cStringList::insert(std::string text) {
    bool rc = listCount < listCapacity;

    if (rc) {
        decVal(first);
        a[first] = text;

        if (listCount == 0) {
            last = first;
        }
        
        listCount++;
    }

    return rc;
}

//******************************************************************************

bool cStringList::add(std::string text) {
    bool rc = listCount < listCapacity;

    if (rc) {
        incVal(last);
        a[last] = text;
        
        if (listCount == 0) {
            first = last;
        }
        
        listCount++;
    }

    return rc;
}

//******************************************************************************
//P3b
bool cStringList::insertAt(int index, std::string text) {
    bool rc = true;

    return rc;
}

//******************************************************************************
//P3b
bool cStringList::deleteAt(int index, std::string &text) {
    bool rc = true;

    return rc;
}

//******************************************************************************
//P3b
bool cStringList::readAt(int index, std::string &text) const {
    bool rc = true;

    return rc;
}

//******************************************************************************

bool cStringList::deleteFirst(std::string &text) {
    bool rc = first;

    if (rc) {
        text = a[first];
        listCount--;

        incVal(first);
        incVal(last);
    }

    return rc;
}

//******************************************************************************

bool cStringList::deleteLast(std::string &text) {
    bool rc = last;

    if (rc) {
        text = a[last];
        listCount--;

        decVal(last);
        decVal(first);
    }
    
    return rc;
}

//******************************************************************************
//P3b
void cStringList::clear() {
    //causes the list to be emptied
    listCount = 0; 
    first = last = 0;
}

//******************************************************************************
//P3b
int cStringList::count() const {
    //return the numbr of entries in the list
    return listCount;
}

//******************************************************************************
//P3b
int cStringList::getIndex(std::string text) const {
    int rc = -1;

    //return the first position at which the text was found;
    //otherwise return -1
    for (int i = 0; i < listCount; i++) {
        if (text == a[i]) {
            rc = i;
            break;
        }
    }

    return -1;
}

//******************************************************************************
//fail to call incVal because printIt is const
void cStringList::printIt() const {
    int userIndex = 0;
    int index = first;

    for (int i=0; i < listCount; i++) {
        cout << userIndex << a[index] <<endl;
        userIndex++;
        //incVal(index);
    }
}