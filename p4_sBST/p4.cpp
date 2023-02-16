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
//Joseph Song & Queena Lee
sNode::sNode(string text) {
    //constructor that causes the object node to be initialized
    this->text = text;
    left = right = NULL;
    h = 1;
}

//******************************************************************************
//Joseph Song & Queena Lee
sBST::sBST() {
    //constructor that causes the object tree to be initialized
    root = NULL;
    treeCount = 0;
}

//******************************************************************************
//Joseph Song & Queena Lee
sBST::~sBST() {
    //deconstructor that deletes all the nodes
    //in preparation for the tree to be destroyed
    clear();
}

//******************************************************************************
//Joseph Song & Queena Lee
string sBST::findMin(sNode *pointer) {
    string rc;

    //returns the minimum value in the subtree
    //whose node is pointed to by pointer
    if (pointer->left) {
        rc = findMin(pointer->left);
    } else {
        rc = pointer->text;
    }
    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
bool sBST::insert(sNode *pointer, string text) {
    bool rc = false;
    sNode *newNode = new sNode(text);


    if (treeCount == 0) {
        root = newNode;
        treeCount++;
        rc = true;
    }

    else if (pointer) {
        //if pointer exists
        //determine if newNode's text is smaller or larger than pointer's text
        //and travel down the tree accordingly
        //insert when it arrives at a leaf
        if (text < pointer->text) {
            if(pointer->left){
                rc = insert(pointer->left, text);
            } else {
                pointer->left = newNode;
                treeCount++;
                rc = true;
            }
        } 
        else if (text > pointer->text) {
            if(pointer->right){
                rc = insert(pointer->right, text);
            } else {
                pointer->right = newNode;
                treeCount++;
                rc = true;
            }
        }

    }


    return rc;
}

//******************************************************************************
//P4b Joseph Song & Queena Lee
bool sBST::remove(sNode *pointer, sNode *removeNode, string text) {
    bool rc = false;

    //if the node to be removed has been found, check for children
    //if right child exists, find the minimum of of the right child
    //copy minimum child to replace the node that needs to be removed
    //otherwise, if left child exist, assign left child in place of removeNode
    //if removeNode is childless, delete the node
    if (removeNode) {
        if (pointer->right) {
            pointer->text = findMin(pointer->right);
            rc = remove(pointer->right, removeNode, pointer->text);
        } else if (pointer->left) {
            sNode *temp = pointer;
            pointer = pointer->left;
            delete temp;
            treeCount--;
        } else {
            delete removeNode;
            treeCount--;
        }
    }

    //check if node's text is equivalent to text to be removed
    //once found, set it as removeNode
    //otherwise, check if text to be removed is to left or right of the pointer
    //determine its path accordingly
    //(is less than to the left, is more than to the right)
    if (pointer->text == text) {
        removeNode = pointer;
    } else if (text < pointer->text) {
        rc = remove(pointer->left, removeNode, text);
    } else if (text > pointer->text) {
        rc = remove(pointer->right, removeNode, text);
    }

    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
bool sBST::isIn(sNode *pointer, string text) const {
    bool rc = false;

    if (pointer) {
        //if pointer exists, check if text in pointer is equivalent to text
        //if text value in pointer is larger than text
        //traverse the left children of the pointer
        //if text value in pointer is smaller than text
        //traverse the right children of the pointer
        if (text < pointer->text) {
            rc = isIn(pointer->left, text);
        } else if (text > pointer->text) {
            rc = isIn(pointer->right, text);
        } else {
            rc = true;
        }
    } 
    return rc; 
}

//******************************************************************************
//Joseph Song & Queena Lee
void sBST::printIt(sNode *pointer) const {
    
    //if pointer exists, traverse the tree
    //and print the text value of the whole tree in ascending order
    //one value per line
    if (pointer) {
        printIt(pointer->left);
        cout << pointer->text << endl;
        printIt(pointer->right);
    }
}

//******************************************************************************
//P4b Joseph Song & Queena Lee
void sBST::clear(sNode *pointer) {

    //if pointer exists, transverse the tree
    //and clear nodes from right to left
    if (pointer) {
        clear(pointer->left);
        clear(pointer->right);
        delete pointer;
    }
}

//******************************************************************************
//Joseph Song & Queena Lee
bool sBST::insert(string text) {
    //isIn is not functioning as intended yet
    
    //if text is not already in the tree
    //insert text into the tree
    //returns true for success
    //returns false if the text value is already in use

    return insert(root, text);
}

//******************************************************************************
//P4b Joseph Song & Queena Lee
bool sBST::remove(string text) {
    //removes the node with that text, deleting the node
    //returns true on success
    //returns false if the node is not found

    //can't get remove to work as intended without resulting in a seg fault
    //remove(root, NULL, text);
    return false;
}

//******************************************************************************
//P4b Joseph Song & Queena Lee
bool sBST::isIn(string text) const {
    //returns true if the node with text value is in the tree
    //otherwise, returns false
    //can't get isIn to function as intended, trying to figure out the issue
    return isIn(root, text);
}

//******************************************************************************
//Joseph Song & Queena Lee
void sBST::printIt() const {
    //results in the BST's text values being printed in ascending order
    printIt(root);
}

//******************************************************************************
//Joseph Song & Queena Lee
int sBST::count() const {
    //returns the number of nodes in the tree
    return treeCount;
}

//******************************************************************************
//P4b Joseph Song & Queena Lee
void sBST::clear() {
    //removes all nodes from the BST, making the BST empty
    clear(root);
    root = NULL;
    treeCount = 0;
}