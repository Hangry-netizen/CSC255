/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 3a
*/

#ifndef __P1_H
#define __P1_H

#include <string>

class cStringList {
    private:
        // a pointer to the array into which the list values will be stored
        std::string *a;

        // memorialize the capacity of the list
        int listCapacity;

        // an integer to record the number of entries in the list
        int listCount;

        // to track the first entry of the list
        int first;

        // to track the last entry of the list
        int last;

        // increments the passed value, wrapping its value to 0 if necessary
        void incVal(int &value);

        // decrements the passed value, wrapping its value to capacity -1 if ncessary
        void decVal(int &value);

    public:
        // constructor that causes the array to be sixed at "capacity" entries
        // has a default listCapacity of 100
        // setting listCount to 0 and first and last also to 0
        cStringList(int listCapacity = 100);

        // deconstructor that deletes the dynamically allocated array "a"
        ~cStringList();
        
        // inserts text at the beginning of the list
        // all other entries shift right
        // returns true if the text was inserted; otherwise, it returns false
        bool insert(std::string text);
        
        // Inserts the given text at the end of the list
        // returns true if the text was added; otherwise, it returns false
        bool add(std::string text);
        
        // Inserts the given text at the index "index"
        // values at that position need to shift right
        // returns true if the text is inserted
        // returns false if the list was full or if the index was greater than listCount
        bool insertAt(int index, std::string text);
        
        // Deletes the text at the given index
        // shifts the entries right of the index to the left.
        // if the index was within the range of the list
        // it sets "text" to the value of the item deleted and returns true
        // otherwise, it does not change "text" and returns false
        bool deleteAt(int index, std::string &text);

        // Returns the text at the given index in the list
        // if the index is invalid, this returns -1
        bool readAt(int index, std::string &text) const;

        // delete the first entry of the array
        // behaves the same as deleteAt(0,text)
        // but it must be independently implemented
        bool deleteFirst(std::string &text);

        // delete the first entry of the array
        // behaves the same as deleteAt(listCount-1,text)
        // but it must be independently implemented
        bool deleteLast(std::string &text);

        // Causes the list to be emptied 
        void clear();

        // Returns the number of entries in the list
        int count() const;

        // Returns the first position at which text was found
        // otherwise, returns -1
        int getIndex(std::string text) const;

        // Causes the list to be printed, one value per line
        // for each line, print the index and the text at that index 
        void printIt() const;
};

#endif