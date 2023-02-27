#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "p6.h"

using namespace std;

void part1(iPQ &myPQ) {
    int i, j;
    int v;
    bool rc;

    //srand(time(NULL));
    srand(0);

    for (i = 0; i < 100; i++) {
	v = rand() % 1000;
	rc = myPQ.enq(v);
	//cout << i << ": enq of " << i << " got " << (rc ? "TRUE" : "FALSE") << endl;
    }

    cout << "Tree count is " << myPQ.count() << endl;
    cout << "Tree contents are: \n";

    myPQ.printIt();


    for (i = 0; i < 10; i++) {
	rc = myPQ.deq(v);
	cout << i << ": deq got " << v << " and " << (rc ? "TRUE" : "FALSE") << endl;
    }

    myPQ.clear();
    cout << "Tree count is now " << myPQ.count() << endl;
}

void part2(iPQ &myPQ) {
    int i;
    int v;
    bool rc;

    //srand(time(NULL));
    srand(0);

    for (i = 0; i < 10; i++) {
	v = rand() % 1000;
	rc = myPQ.enq(v);
	// cout << i << ": enq of " << i << " got " << (rc ? "TRUE" : "FALSE") << endl;
    }

    cout << "Tree count is " << myPQ.count() << endl;
    cout << "Tree contents are: \n";

    myPQ.printIt();


    for (i = 0; myPQ.deq(v); i++) {
	cout << i << ": deq got " << v << endl;
    }
    myPQ.clear();
}

main(int argc, char *argv[]) {
    iPQ myPQ(200);

    part1(myPQ);
    part2(myPQ);
    cout << "all done \n";
}
