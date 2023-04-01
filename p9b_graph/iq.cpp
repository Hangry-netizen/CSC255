#include <iostream>
#include <fstream>

#include "iq.h"

using namespace std;

//******************************************************************************
//Joseph Song & Queena Lee
iQ::iQ(int n) {
    theList = new cIntList(n);
}

//******************************************************************************
//Joseph Song & Queena Lee
iQ::~iQ() {
    theList->~cIntList();
}

//******************************************************************************
//Joseph Song & Queena Lee
// enqueue value v into the iQ
bool iQ::enq(int v) {
    return theList->add(v);
}

//******************************************************************************
//Joseph Song & Queena Lee
// dequeue the oldest value, return it in v
// return true if queue had something, false if empty
// also set v to -1 for returning from an empty iQ
bool iQ::deq(int &v) {

    bool rc = theList->count();
    v = -1;

    if(rc){
        theList->deleteFirst(v);
    }
    
    return rc;
}

//******************************************************************************
//Joseph Song & Queena Lee
// remove all items in the iQ, resulting in an empty iQ
void iQ::clear() {
    theList->clear();
}

//******************************************************************************
//Joseph Song & Queena Lee
// return the number of items in the iQ
int iQ::count() const {
    return theList->count();
}

//******************************************************************************
//Joseph Song & Queena Lee
// print the contents of the iQ
void iQ::printIt() const {
    theList->printIt();
}