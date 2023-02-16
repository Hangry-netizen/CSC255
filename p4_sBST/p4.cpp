/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 4b
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
    clear(root);
}

//******************************************************************************
//Joseph Song & Queena Lee
string sBST::findMin(sNode *pointer) {
    string rc = pointer->text;

    //returns the minimum value in the subtree
    //whose node is pointed to by pointer
    if (pointer->left) {
        rc = findMin(pointer->left);
    }

    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
bool sBST::insert(sNode *&pointer, string text) {
    bool rc = false;

    if (pointer) {
        //if pointer exists
        if (text < pointer->text) {
            //if text is less than pointer's text, travel left
            rc = insert(pointer->left, text);
        } 
        else if (text > pointer->text) {
            //if text is more than pointer's text, travel right
            rc = insert(pointer->right, text);
        }
    } else {
        //otherwise, we are at a leaf and we will insert the new node here
        pointer = new sNode(text);
        treeCount++;
        rc = true;
    }

    return rc;
}

//******************************************************************************
//P4b Joseph Song & Queena Lee
bool sBST::remove(sNode *&pointer, string text) {
    bool rc = false;

    if (pointer) {
        //if pointer exists, check if text is > or < than pointer's text
        if (text < pointer->text) {
            rc = remove(pointer->left, text);
        } else if (text > pointer->text) {
            rc = remove(pointer->right, text);
        } else {
            //if text is equivalent to pointer's text, check for right child
            if (pointer->right) {
                //if right child exists
                //get the min of right child to replace the node to be removed
                pointer->text = findMin(pointer->right);
                rc = remove(pointer->right, pointer->text);
            } else {
                //otherwise, if only left child exists
                //copy left child to replace the node to be removed
                sNode *temp = pointer;
                pointer = pointer->left;
                delete temp;
                treeCount--;
                rc = true;
            }
        }
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
    //call insert's recursion helper
    //results in true if text is inserted
    //otherwise, results in false
    return insert(root, text);
}

//******************************************************************************
//P4b Joseph Song & Queena Lee
bool sBST::remove(string text) {
    //call remove's recursion helper
    //results in true if text is removed
    //otherwise, results in false
    return remove(root, text);
}

//******************************************************************************
//P4b Joseph Song & Queena Lee
bool sBST::isIn(string text) const {
    //call isIn's recursion helper
    //results in true if text is in the tree
    //otherwise, results in false
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