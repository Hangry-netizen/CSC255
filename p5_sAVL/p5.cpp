/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 5b
*/

#include <iostream>
#include <fstream>

#include "p5.h"

using namespace std;

//******************************************************************************
//Joseph Song & Queena Lee
int max(int a, int b) {
    //function to determine the maximum of two given integers
    int max = a;

    if (b > max) {
        max = b;
    }

    return max;
}

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
sAVL::sAVL() {
    //constructor that causes the object tree to be initialized
    root = NULL;
    treeCount = 0;
}

//******************************************************************************
//Joseph Song & Queena Lee
sAVL::~sAVL() {
    //deconstructor that deletes all the nodes
    //in preparation for the tree to be destroyed
    clear(root);
}

//******************************************************************************
//Joseph Song & Queena Lee
string sAVL::findMin(sNode *p) const {
    string rc = p->text;

    //returns the minimum value in the subtree
    //whose node is pointed to by pointer
    if (p->left) {
        rc = findMin(p->left);
    }

    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
bool sAVL::insert(sNode *&p, string text) {
    bool rc = false;

    if (p) {
        //if pointer exists
        if (text < p->text) {
            //if text is less than pointer's text, travel left
            rc = insert(p->left, text);
        } 
        else if (text > p->text) {
            //if text is more than pointer's text, travel right
            rc = insert(p->right, text);
        }
    } else {
        //otherwise, we are at a leaf and we will insert the new node here
        p = new sNode(text);
        treeCount++;
        rc = true;
        
        bal(p);
        p->h = calcHeight(p);
    }
    //balance p
    bal(p);

    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
bool sAVL::remove(sNode *&p, string text) {
    bool rc = false;

    if (p) {
        //if pointer exists, check if text is > or < than pointer's text
        if (text < p->text) {
            rc = remove(p->left, text);
        } else if (text > p->text) {
            rc = remove(p->right, text);
        } else {
            //if text is equivalent to pointer's text, check for right child
            if (p->right) {
                //if right child exists
                //get the min of right child to replace the node to be removed
                p->text = findMin(p->right);
                rc = remove(p->right, p->text);
            } else {
                //otherwise, if only left child exists
                //copy left child to replace the node to be removed
                sNode *temp = p;
                p = p->left;
                delete temp;
                treeCount--;
                rc = true;
            }
        }
    }
    
    //balance p
    bal(p);

    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
bool sAVL::isIn(sNode *p, string text) const {
    bool rc = false;

    if (p) {
        //if pointer exists, check if text in pointer is equivalent to text
        //if text value in pointer is larger than text
        //traverse the left children of the pointer
        //if text value in pointer is smaller than text
        //traverse the right children of the pointer
        //return true if text is in the tree
        if (text < p->text) {
            rc = isIn(p->left, text);
        } else if (text > p->text) {
            rc = isIn(p->right, text);
        } else {
            rc = true;
        }
    } 
    return rc; 
}

//******************************************************************************
//Joseph Song & Queena Lee
void sAVL::printIt(sNode *p, int &index) const {
    if (p) {
        //if pointer exists, traverse the tree
        //and print entries from left to right, with their index and height
        printIt(p->left, index);
        cout << "At " << index++ << " the string is " << p->text;
        cout << ": height = " << p->h << endl;
        printIt(p->right, index);
    }
}

//******************************************************************************
//Joseph Song & Queena Lee
void sAVL::clear(sNode *p) {

    //if pointer exists, transverse the tree 
    //and clear all nodes from right to left
    if (p) {
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

//******************************************************************************
//Joseph Song & Queena Lee
void sAVL::rotateLeft(sNode *&p1) {
    //rotate left around p1
    sNode *p2 = p1->right;
    p1->right = p2->left;
    p2->left = p1;

    //recalculate height since positions have been changed
    p1->h = calcHeight(p1);
    p2->h = calcHeight(p2);
    p1 = p2;
}

//******************************************************************************
//Joseph Song & Queena Lee
void sAVL::rotateRight(sNode *&p1) {
    //rotate right around p1
    sNode *p2 = p1->left;
    p1->left = p2->right;
    p2->right = p1;

    //recalculate height since positions have been changed
    p1->h = calcHeight(p1);
    p2->h = calcHeight(p2);
    p1 = p2;
}

//******************************************************************************
//Joseph Song & Queena Lee
void sAVL::bal(sNode *&p1) {
    if(p1) {
        int diff = height(p1->left) - height(p1->right);

        if (diff == 2) {
            //Left heavy - rotoate right
            diff = height(p1->left->left) - height(p1->left->right);
            if (diff < 0) {
                //Left-right heavy - rotate left then rotate right
                rotateLeft(p1->left);
            }
            rotateRight(p1);
        } else if (diff == -2) {
            //Right heavy - rotate left
            if (height(p1->right->left) > height(p1->right->right)) {
                //Right-left heavy - rotate right then rotate left
                rotateRight(p1->right);
            }
            rotateLeft(p1);
        }
        //recalculate p's height
        p1->h = calcHeight(p1);
    }

}

//******************************************************************************
//Joseph Song & Queena Lee
int sAVL::height(sNode *p) const {
    //return the height of p
    //return 0 if p is NULL
    int rc = 0;

    if (p) {
        rc = p->h;
    }

    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
int sAVL::calcHeight(sNode *p) const {
    //compare the height of the left child and the height of the right child
    //add 1 to the larger number for own height
    return max(height(p->left), height(p->right)) + 1;
}

//******************************************************************************
//Joseph Song & Queena Lee
bool sAVL::insert(string text) {
    //call insert's recursion helper
    //results in true if text is inserted
    //otherwise, results in false
    return insert(root, text);
}

//******************************************************************************
//Joseph Song & Queena Lee
bool sAVL::remove(string text) {
    //call remove's recursion helper
    //results in true if text is removed
    //otherwise, results in false
    return remove(root, text);
}

//******************************************************************************
//Joseph Song & Queena Lee
bool sAVL::isIn(string text) const {
    //call isIn's recursion helper
    //results in true if text is in the tree
    //otherwise, results in false
    return isIn(root, text);
}

//******************************************************************************
//Joseph Song & Queena Lee
void sAVL::printIt() const {
    //results in the BST's text values being printed in ascending order
    //with its index number
    int index = 0;
    printIt(root, index);
}

//******************************************************************************
//Joseph Song & Queena Lee
int sAVL::count() const {
    //returns the number of nodes in the tree
    return treeCount;
}

//******************************************************************************
//Joseph Song & Queena Lee
void sAVL::clear() {
    //removes all nodes from the BST, making the BST empty
    clear(root);
    root = NULL;
    treeCount = 0;
}