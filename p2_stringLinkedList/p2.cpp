#include <iostream>
#include "p2.h"

using namespace std;

//******************************************************************************

stringLinkedList::stringLinkedList() {
    first = last = NULL;
    listCount = 0;
}

//******************************************************************************

stringLinkedList::~stringLinkedList() {

}

//******************************************************************************

bool stringLinkedList::insert(std::string text) {
    bool listExist = first;

    node *newNode = new node(text, first);

    if (!listExist) {
        last = newNode;
    }
    
    first = newNode;
    listCount++;

    return true;
}

//******************************************************************************

bool stringLinkedList::add(std::string text) {    
    //create new node pointing to null
    node *newNode = new node(text);

    //if there is an existing list, set the pointer of the last node to the newNode
    //otherwise, let first point to the newNode
    if (last) {
        last -> next = newNode;
    } else {
        first = newNode;
    }
    
    //set newNode as last entry and increment listCount
    last = newNode;
    listCount++;

    return true;
}

//******************************************************************************

bool stringLinkedList::insertAt(int index, std::string text) {
    //determine if index is withtin listCount range (0 <= index <= listCount)
    bool rc = !((index < 0) || (index > listCount));

    if (rc) {
        if (index == 0) {
            //if index is 0, insert newNode at the beginning of the list
            node *newNode = new node(text, first);
            first = newNode;
            
        } else {
            //if index is within listCount range (index != 0)
            //get to the given index
            node *pointer = first;
            int count = 0;
            
            while (count < (index)) {
                pointer = pointer -> next;
                count++;
            }
    
            //at the index location, create newNode
            //have the newNode pointing to the node to its right
            //and the previous node pointing to newNode
            node *newNode = new node(text, pointer->next);
            
            pointer -> next = newNode;
        }
    
        listCount++;
    }

    return rc;
}
