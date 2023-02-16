/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 4b
*/

#ifndef __P4_H
#define __P4_H

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
        
        friend class sBST;
};

class sBST {
    private:
        //records the number of entries in the BST
        int treeCount;

        //to point to the tree of nodes
        sNode *root;

        //returns the minimum value in the subtree
        //whose root node is pointed to by ptr
        std::string findMin(sNode *ptr);

        //recursion helpers
        bool insert(sNode *&pointer, std::string text);
        bool remove(sNode *&pointer, std::string text);
        bool isIn(sNode *pointer, std::string text) const;
        void printIt(sNode *pointer) const;
        void clear(sNode *pointer);

    public:
        //constructor that causes object to be initialized
        sBST();

        //destructor that deletes all the nodes in the BST
        //in preparation for the BST to be destroyed
        ~sBST();

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

        //results in the BST's text values being printed
        //in ascending order, one value per line
        void printIt() const;

        //returns the number of nodes in the tree
        int count() const;

        //removes all nodes from the BST, making the BST empty
        void clear();
};

#endif