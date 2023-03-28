/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 1
*/

#ifndef __P1_H
#define __P1_H

#include <string>

class intList {
    private:
        // an array to store the list
        int *a;
        
        // to track the capacity of the list
        int listCapacity;

        // to track the size of the list
        int listSize;

    public:
        // Array is sized to a default capacity of 100
        intList(int listCapacity = 100);

        // Deletes the dynamically allocated array "a"
        ~intList();
        
        // Inserts the given key at the beginning of the list
        // all other entries shift right
        // returns true if the key was inserted; otherwise, it returns false
        bool insert(int key);
        
        // Inserts the given key at the end of the list
        // returns true if the key was added; otherwise, it returns false
        bool add(int key);
        
        // Inserts the given key at the index "index"
        // values at that position need to shift right
        // returns true if the key is inserted
        // returns false if the list was full or if the index was greater than listSize
        bool insertAt(int index, int key);
        
        // Deletes the key at the given index
        // shifts the entries right of the index to the left.
        // if the index was within the range of the list
        // it sets "key" to the value of the item deleted and returns true
        // otherwise, it does not change "key" and returns false
        bool deleteAt(int index, int &key);

        // Causes the list to be emptied 
        void clear();
        
        // Returns the key at the given index in the list
        // if the index is invalid, this returns -1
        int readAt(int index) const;

        // Returns the first position at which key was found
        // otherwise, returns -1
        int find(int key) const;

        // Causes the list to be printed, one value per line
        // for each line, print the index and the key at that index 
        void printIt(int n) const;
        
        // Returns the number of entries in the list
        int count() const;

        // Returns the number of entries in the list
        int capacity() const;
};

#endif