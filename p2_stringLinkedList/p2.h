/*
* Jospeh Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 2a
*/

#ifndef __P1_H
#define __P1_H

#include <string>

class node {
    private:
        std::string text;
        node *next;
        node(std::string text="", node *pn=NULL);
        friend class stringLinkedList;
};

class stringLinkedList {
    private:
        node *first, *last;
        
        //to record the number of entries in the list
        int listCount; 

        //recursion helper
        int getIndex(std::string text, node *pn, int index) const;

        //recursion helper
        void printIt(node *pn, int index) const;

        //recursion helper
        void clear(node *pn);
    public:
        //causes the object to be initialized
        //(first = last = NULL and count 0)
        stringLinkedList();

        //deletes the dynamically allocated nodes in the list
        ~stringLinkedList();

        //MODIFIERS
        
        //inserts the string at the beginning of the list
        //returns whether the string was inserted
        bool insert(std::string text);

        //appends the string to the end of the list
        //returns whether the string was added
        bool add(std::string text);

        //inserts the string at the index "index"
        //presuming 0 <= index <= length()
        //entries at that position need to shift right
        //return true if the entry was inserted; false otherwise
        bool insertAt(int index, std::string text);
        
        //P2b
        //deletes the entry at the given index
        // Returns true if the index was within 0 <= index < length()
        //returns false otherwise
        //If the delete takes place
        //it returns the string in the deleted node
        //via the reference parameter "text”
        bool deleteAt(int index, std::string &text);
        
        //P2b
        bool readAt(int index, std::string &text) const;

        //causes the list to be emptied
        //all dynamically allocated memory should be deleted
        void clear();

        //NON-MODIFIERS

        //P2b
        int getIndex(std::string text) const;

        //causes the list to be printed
        //for each line, print the index and the string at that index
        //this must be implemented with recursion, not a loop
        void printIt() const;

        //returns the number of entries in the list, listCount
        int count() const;
};

#endif