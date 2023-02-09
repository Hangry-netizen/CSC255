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
//Queena Lee
cStringList::cStringList(int listCapacity) {
    //constructor that causes array to be sized at listCapacity entries
    //with a default capacity of 100
    //initialize listCount, first, and last to 0
    a = new std::string[listCapacity];
    this->listCapacity = listCapacity;
    listCount = 0;
    first = last = 0;
}

//******************************************************************************
//Queena Lee
cStringList::~cStringList() {
    if (a != 0) {
        //if array exists, delete the dynamically allocated array
        delete[] a;
        a = NULL;
    }
}

//******************************************************************************
//Joseph Song & Queena Lee
void cStringList::incVal(int &value) {
    //increment index value
    value = value + 1;
    value = value % listCapacity;
}

//******************************************************************************
//Joseph Song & Queena Lee
void cStringList::decVal(int &value) {
    //decrement index value
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
        //if there is capacity, insert text at the beginning of the array
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
        //if there is capacity, add text at the end of the array
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
//Joseph Song & Queena Lee
bool cStringList::insertAt(int userIndex, std::string text) {
    bool rc = (listCount < listCapacity) && (userIndex <= listCount) && (userIndex >= 0);
    int pIndex = last;
    int ind;
    string t;

    if (rc) {
        if (userIndex == 0){
            insert(text);
        }
        else if (userIndex == listCount){
            add(text);
        }
        else{
            for (int i = listCount; i > userIndex; i--) {

                t = a[pIndex];
                ind = pIndex;

                incVal(ind);
                a[ind] = t;

                decVal(pIndex);
            }
            incVal(pIndex);
            a[pIndex] = text;
            listCount++;
            incVal(last);
        }
    }

    return rc;
}

//******************************************************************************
//Joseph Song
bool cStringList::deleteAt(int index, std::string &text) {
    // If the index is not within listCount, it returns false.
    bool rc = (index < listCount) && (index >= 0);
    // pIndex moves from first to last 
    int pIndex = first;
    // Temporary space to storage current index
    int ind;

    if (rc) {
        
        for (int i = 0; i < listCount; i++) {
            // If index is i, get text
            if (index == i){
                text = a[pIndex];
            }
    
            // If the current location is behind a given index
            // shifts the entries to the left 
            else if (index < i){
                ind = pIndex;
                decVal(ind);
                a[ind] = a[pIndex];
            }

            // Increment pIndex so that the pIndex continues
            incVal(pIndex);
        }

        listCount--;
        // Decrement last index
        decVal(last);

        // If listCount becomes empty after listCount--
        // Rearrange first and last to 0 
        if(listCount == 0){
            first = last = 0;
        }
    }
    return rc;
}

//******************************************************************************
//P3b
bool cStringList::readAt(int index, std::string &text) const {
    bool rc = false;
    int pIndex = first;

    // If index is within listCount
    if ((index >= 0) && (index < listCount)) {
        for (int i = 0; i < listCount; i++) {
            if (index == i){
                text = a[pIndex];
            }
            pIndex = pIndex + 1;
            pIndex = pIndex % listCapacity;
        }
        // Return true if text is within list
        // Otherwise return false
        rc = true;
    }
    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
bool cStringList::deleteFirst(std::string &text) {
    bool rc = listCount;

    if (rc) {
        //if list is not empty, delete the first entry on the list
        text = a[first];
        listCount--;

        incVal(first);

        if (listCount == 0) {
            //if list is empty after deletion
            //increment last so that it doesn't point to the same index as first
            last = first;
        }
    }

    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
bool cStringList::deleteLast(std::string &text) {
    bool rc = listCount;

    if (rc) {
        //if list is not empty, delete the last entry on the list
        text = a[last];
        listCount--;

        decVal(last);
        
        if (listCount == 0) {
            //if list is empty after deletion
            //increment first so that it points to the same index as first
            first = last;
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
    //return the number of entries in the list
    return listCount;
}

//******************************************************************************
//Joseph Song & Queena Lee
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

    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
void cStringList::printIt() const {
    int index = first;
    
    //print the index (from the user's perspective) and text of each entry
    for (int userIndex = 0; userIndex < listCount; userIndex++) {
        cout << "At pos " << userIndex << " there is " << a[index] <<endl;

        index = index + 1;
        index = index % listCapacity;
    }
}
