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
//Joseph Song & Queena Lee
cStringList::cStringList(int listCapacity) {
    a = new std::string[listCapacity];
    this->listCapacity = listCapacity;
    listCount = 0;
    first = last = 0;
}

//******************************************************************************
//Joseph Song & Queena Lee
cStringList::~cStringList() {
    if (a != 0) {
        delete[] a;
        a = NULL;
    }
}

//******************************************************************************
//Joseph Song & Queena Lee
void cStringList::incVal(int &value) {
    value = value + 1;
    value = value % listCapacity;
}

//******************************************************************************
//Joseph Song & Queena Lee
void cStringList::decVal(int &value) {
    value = value - 1;
    if (value < 0) {
        value = listCapacity - 1;
    }
}

//******************************************************************************
//Joseph Song & Queena Lee
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
//Joseph Song & Queena Lee
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
//Joseph Song & Queena Lee
bool cStringList::deleteFirst(std::string &text) {
    bool rc = listCount;

    if (rc) {
        text = a[first];
        listCount--;

        incVal(first);

        if (listCount == 0) {
            incVal(last);
        }
    }

    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
bool cStringList::deleteLast(std::string &text) {
    bool rc = listCount;

    if (rc) {
        text = a[last];
        listCount--;

        decVal(last);
        
        if (listCount == 0) {
            decVal(first);
        }
    }
    
    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
void cStringList::clear() {
    //causes the list to be emptied
    listCount = 0; 
    first = last = 0;
}

//******************************************************************************
//Joseph Song & Queena Lee
int cStringList::count() const {
    //return the numbr of entries in the list
    return listCount;
}

//******************************************************************************
//P3b
int cStringList::getIndex(std::string text) const {
    int rc = -1;
    int index = first;

    //return the first position at which the text was found;
    //otherwise return -1
    for (int userIndex = 0; userIndex < listCount; userIndex++) {
        if (text == a[index]) {
            rc = userIndex;
            break;
        }
        index = index + 1;
        index = index % listCapacity;
    }

    return -1;
}

//******************************************************************************
//Joseph Song & Queena Lee
void cStringList::printIt() const {
    int index = first;

    for (int userIndex = 0; userIndex < listCount; userIndex++) {
        cout << userIndex << a[index] <<endl;

        //Is there a way to use the incVal(index) function instead of
        //copying and pasting the same body code to increment index?
        //Can't use incVal(index) because printIt is declared as const,
        //but incVal doesn't make any data changes

        index = index + 1;
        index = index % listCapacity;
    }
}