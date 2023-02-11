/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 4a
*/

#include <iostream>
#include <fstream>

#include "p4.h"

using namespace std;

//******************************************************************************

sNode::sNode(string text) {
    this->text = text;
    left = right = NULL;
    h = 1;
}

//******************************************************************************

sBST::sBST(){
    root = NULL;
    treeCount = 0;
}

//******************************************************************************

sBST::~sBST() {
    clear();
}

//******************************************************************************
void sBST::insert(sNode *pointer, sNode *newNode) {
    if (pointer) {
        if (newNode->text < pointer->text) {
            if (pointer->left) {
                insert(pointer->left, newNode);
            } else {
                pointer->left = newNode;
            }
    
        } else if (newNode->text > pointer->text) {
            if (pointer->right) {
                insert(pointer->right, newNode);
            } else {
                pointer->right = newNode;
            }
        }
        
        pointer->h += 1;
    }
}

//******************************************************************************

void sBST::remove() {

}

//******************************************************************************

bool sBST::isIn(sNode *pointer, string text) const {
    bool rc = false;
    
    if (pointer) {
        if (pointer->text == text) {
            rc = true;
        } else {
            isIn(pointer->left, text);
            isIn(pointer->right, text);
        }
    }
    return rc;
}

//******************************************************************************

void sBST::printIt(sNode *pointer) const {
    if (pointer) {
        printIt(pointer->left);
        cout << pointer->text << endl;
        printIt(pointer->right);
    }
}

//******************************************************************************

void sBST::clear(sNode *pointer) {

}

//******************************************************************************

bool sBST::insert(string text) {
    bool rc = !(isIn(root, text));

    if (rc) {
        sNode *newNode = new sNode(text);

        if (treeCount == 0) {
            root = newNode;
        } else {
            insert(root, newNode);
        }
        
        treeCount++;
    }

    return rc;
}

//******************************************************************************

bool sBST::remove(string text) {
    return true;
}

//******************************************************************************

bool sBST::isIn(string text) const {
    return isIn(root, text);
}

//******************************************************************************

void sBST::printIt() const {
    printIt(root);
}

//******************************************************************************

int sBST::count() const {
    return treeCount;
}

//******************************************************************************

void sBST::clear() {

}