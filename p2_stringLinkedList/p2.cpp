/*
* Jospeh Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 2a
*/

#include <iostream>
#include <fstream>

#include "p2.h"

using namespace std;

//******************************************************************************
// Queena Lee
node::node(std::string text, node *pn) {
    this->text = text;
    next = pn;
}

//******************************************************************************
// Joseph Song & Queena Lee
stringLinkedList::stringLinkedList() {
    //initialize first, last, and listCount
    first = last = NULL;
    listCount = 0;
}

//******************************************************************************
// Queena Lee
stringLinkedList::~stringLinkedList() {
    //delete all nodes
    clear(first);
    delete first;
    delete last;
}

//******************************************************************************
// Queena Lee
int stringLinkedList::getIndex(std::string text, node *pn, int index) const {
    int rc = -1;

    if (pn) {
        //if list is not empty
        //returns the first position at which the value was found
        //otherwise, returns -1
        if (pn->text == text) {
            rc = index;
        } else {
            rc = getIndex(text, pn->next, index+1);
        }
    }
    return rc;
}

//******************************************************************************
// Joseph Song
void stringLinkedList::printIt(node *pn, int index) const {
    if (pn) {
        //if index exists within listCount range
        //print list and recurse function until the end of the list
        cout << "At pos "<< index << " there is " << pn->text << endl;

        printIt(pn->next, index+1);
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
void stringLinkedList::clear(node *pn) {
    if (pn) {
        //if a node exists, go to the end of the list
        //and delete nodes starting from the end of the list
        clear(pn->next);
        delete pn;
    }
}

//******************************************************************************
// Joseph Song
bool stringLinkedList::insert(std::string text) {
    //create new node pointing to the value of first
    node *newNode = new node(text, first);

    //if there is no existing list, set newNode as last
    if (!listCount) {
        last = newNode;
    }

    //set newNode as first entry and increment listCount
    first = newNode;
    listCount++;

    return true;
}

//******************************************************************************
// Joseph Song
bool stringLinkedList::add(std::string text) {    
    //create new node pointing to null
    node *newNode = new node(text);

    //if there is an existing list
    //set the pointer of the last node to the newNode
    //otherwise, set newNode as first entry as well
    if (last) {
        last->next = newNode;
    } else {
        first = newNode;
    }
    
    //set newNode as last entry and increment listCount
    last = newNode;
    listCount++;

    return true;
}

//******************************************************************************
// Queena Lee
bool stringLinkedList::insertAt(int index, std::string text) {
    //determine if index is withtin listCount range (0 <= index <= listCount)
    bool rc = (index >= 0) && (index <= listCount);

    if (rc) {
        node *newNode = new node(text);
        if (index == 0) {
            //if index is 0, insert newNode at the beginning of the list
            newNode->next = first;
            first = newNode;
            if (listCount == 0) {
                //if list is empty, set newNode as first and last on the list
                last = first;
            }
        } else if (index == listCount) {
            //if index is the last index, point the last node to newNode
            //set newNode as last on the list
            last->next = newNode;
            last = newNode;
        } else {
            //if index is within listCount range and larger than 0
            //get to the given index
            node *pointer = first;
            
            for (int i = 0; i < index-1; i++) {
                pointer = pointer->next;
            }

            //at the index location, point newNode to the node on its right
            //and set the node on its left to point to newNode
            newNode->next = pointer->next;
            pointer->next = newNode;
        }
        listCount++;
    }

    return rc;

}

//******************************************************************************
// Joseph Song & Queena Lee
bool stringLinkedList::deleteAt(int index, std::string &text) {
    bool rc = ((index >= 0) && (index < listCount));

    if (rc) {
        //if index is within listCount range
        //delete the entry at the given index
        node *pointer = first;
        if (index == 0) {
            //if index is the first on the list
            //get text, change first pointer, delete node
            text = first->text;
            first = first->next;
            delete pointer;
        } else {
            //get to the node left to the given index
            //get text, change pointer to point to the node to the right of index
            //delete node            
            for (int i = 0; i < index-1; i++) {
                pointer = pointer->next;
            }
            text = pointer->next->text;
            delete pointer->next;
            pointer->next = pointer->next->next;

            if (index == listCount-1) {
                last == pointer;
            }
        }
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool stringLinkedList::readAt(int index, std::string &text) const {
    bool rc = ((index >= 0) && (index < listCount));

    if (rc) {
        //if index is within listCount range
        //read the entry at the given index
        node *pointer = first;
        //get to the node at the given index
        //return text at the given index          
        for (int i = 0; i < index; i++) {
            pointer = pointer->next;
        }

        text = pointer->text;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
void stringLinkedList::clear() { 
    //call recursion helper
    clear(first);

    //clear first, last, and listCount variables
    first = last = NULL;
    listCount = 0;
}

//******************************************************************************
// Queena Lee
int stringLinkedList::getIndex(std::string text) const{
    //return the first position at which the value was found
    //otherwise, returns -1
    return getIndex(text, first, 0);
}

//******************************************************************************
// Joseph Song
void stringLinkedList::printIt() const {
    //if list exists, print list starting from the first node
    printIt(first, 0);
}

//******************************************************************************
// Joseph Song & Queena Lee
int stringLinkedList::count() const {
    //return the number of entries in the list, listCount
    return listCount;
}