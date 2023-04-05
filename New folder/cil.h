/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 3b
*/

#ifndef __P3_H
#define __P3_H


class cIntList {
    private:
        // a pointer to the array into which the list values will be stored
        int *a;

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

        // decrements the passed value, wrapping its value to
        // capacity -1 if ncessary
        void decVal(int &value);

    public:
        // constructor that causes the array to be sixed at "capacity" entries
        // has a default listCapacity of 100
        // setting listCount to 0 and first and last also to 0
        cIntList(int listCapacity = 100);

        // deconstructor that deletes the dynamically allocated array "a"
        ~cIntList();
        
        // inserts value at the beginning of the list
        // all other entries shift right
        // returns true if the value was inserted; otherwise, it returns false
        bool insert(int value);
        
        // Inserts the given value at the end of the list
        // returns true if the value was added; otherwise, it returns false
        bool add(int value);
        
        // Inserts the given value at the index "index"
        // values at that position need to shift right
        // returns true if the value is inserted
        // returns false if the list was full
        //or if the index was greater than listCount
        bool insertAt(int index, int value);
        
        // Deletes the value at the given index
        // shifts the entries right of the index to the left.
        // if the index was within the range of the list
        // it sets "value" to the value of the item deleted and returns true
        // otherwise, it does not change "value" and returns false
        bool deleteAt(int index, int &value);

        // Returns the value at the given index in the list
        // if the index is invalid, this returns -1
        bool readAt(int index, int &value) const;

        // delete the first entry of the array
        // behaves the same as deleteAt(0,value)
        // but it must be independently implemented
        bool deleteFirst(int &value);

        // delete the first entry of the array
        // behaves the same as deleteAt(listCount-1,value)
        // but it must be independently implemented
        bool deleteLast(int &value);

        // Causes the list to be emptied 
        void clear();

        // Returns the number of entries in the list
        int count() const;

        // Returns the first position at which value was found
        // otherwise, returns -1
        int getIndex(int value) const;

        // Causes the list to be printed, one value per line
        // for each line, print the index and the value at that index 
        void printIt() const;
};

#endif