/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 5b
*/

#ifndef __P5_H
#define __P5_H

#include <string>

class sNode {
    private:
        //holds the node's key
        std::string text;

        //for future use
        int h;

        //left and right children pointers
        sNode *left, *right;

        //node constructor
        sNode(std::string text = "");
        
        friend class sAVL;
};

class sAVL {
    private:
        //records the number of entries in the BST
        int treeCount;

        //to point to the tree of nodes
        sNode *root;

        //returns the minimum value in the subtree
        //whose root node is pointed to by ptr
        std::string findMin(sNode *p) const;

        //recursion helpers
        bool insert(sNode *&p, std::string text);
        bool remove(sNode *&p, std::string text);
        bool isIn(sNode *p, std::string text) const;
        void printIt(sNode *p, int &index) const;
        void clear(sNode *p);

        //rotateLeft when p1 is a node that is right heavy imbalanced
        void rotateLeft(sNode *&p1);

        //rotateRight when p1 is a node that is left heavy imbalanced
        void rotateRight(sNode *&p1);

        //to balance pointer
        void bal(sNode * &p1);

        //returns the height of p if it is real
        //otherwise 0 if it is NULL
        int height(sNode *p) const;

        ////return the calculation of p's height
        //based on the height of its children
        //this is not a recursive call
        int calcHeight(sNode *p) const;

    public:
        //constructor that causes object to be initialized
        sAVL();

        //destructor that deletes all the nodes in the BST
        //in preparation for the BST to be destroyed
        ~sAVL();

        //inserts the text into the tree
        //returns true for success
        //returns false if the text value is already in the tree
        bool insert(std::string text);

        //removes the node with that text, deleting the node
        //returns true for success
        //returns false if the text is already in the tree
        bool remove(std::string text);

        //returns true if the node with text value is in the tree
        //otherwise returns false
        bool isIn(std::string text) const;

        //print the height of each node and its "index"
        void printIt() const;

        //returns the number of nodes in the tree
        int count() const;

        //removes all nodes from the BST, making the BST empty
        void clear();
};

#endif