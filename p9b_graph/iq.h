#ifndef __IQ_H
#define __IQ_H

#include "cil.h"

class iQ {
    private:
        cIntList *theList;
    public:
        // constructor with default size
        iQ(int n = 100);
        
        // destructor
        ~iQ();
        
        // enqueue value v into the iQ
        bool enq(int v);
        
        // dequeue the oldest value, return it in v
        // return true if queue had something, false if empty
        // also set v to -1 for returning from an empty iQ
        bool deq(int &v);
        
        // remove all items in the iQ, resulting in an empty iQ
        void clear();
        
        // return the number of items in the iQ
        int count() const;
        
        // print the contents of the iQ
        void printIt() const;
};

#endif