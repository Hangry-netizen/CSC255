/*
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 1b
*/

#ifndef __P1_H
#define __P1_H

#include <string>

class stringList {
    private:
        std::string *a;
        int listCapacity;
        int listSize;

    public:
        // Array is sized to a default capacity of 100
        stringList(int listCapacity = 100);

        // Deletes the dynamically allocated array "a"
        ~stringList();
        
        // Inserts the given text at the beginning of the list
        // all other entries shift right
        // returns true if the text was inserted; otherwise, it returns false
        bool insert(std::string text);
        
        // Inserts the given text at the end of the list
        // returns true if the text was added; otherwise, it returns false
        bool add(std::string text);
        
        // Inserts the given text at the index "index"
        // values at that position need to shift right
        // returns true if the text is inserted
        // returns false if the list was full or if the index was greater than listSize
        bool insertAt(int index, std::string text);
        
        // Deletes the text at the given index
        // shifts the entries right of the index to the left.
        // if the index was within the range of the list
        // it sets "text" to the value of the item deleted and returns true
        // otherwise, it does not change "text" and returns false
        bool deleteAt(int index, std::string &text);

        // Causes the list to be emptied 
        void clear();
        
        // Returns the text at the given index in the list
        // if the index is invalid, this returns -1
        bool readAt(int index, std::string &text) const;

        // Returns the first position at which text was found
        // otherwise, returns -1
        int getIndex(std::string text) const;

        // Causes the list to be printed, one value per line
        // for each line, print the index and the text at that index 
        void printIt() const;
        
        // Returns the number of entries in the list
        int count() const;
};

#endif