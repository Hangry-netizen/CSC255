#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "p5.h"

using namespace std;
long const OneMillion = 1000000;
long const OneBillion = OneMillion * 1000L;
int const NCOUNT = OneMillion;
long const NCOUNT2 = 2000;

double getElapsedTime(timespec start, timespec end) {
    // returns number of ms
    unsigned long long diff;
    diff = OneBillion * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    return(((double) diff)/1000000.0);
}

//***********************************************************************

string myToString(int v) {
    string text;
    char a[20];
    sprintf(a, "%010d", v);

    text = a;

    return text;
}

//***********************************************************************

void doWork(sAVL &tree) {
    int i, j;
    int v;
    bool rc;

    struct timespec tStart, tStop;


    cout << "Do WorkBST - START   ********************\n";
    for (j = 0; j < 2; j++) {
	//
	// TIMING INSERTION
	//
	clock_gettime(CLOCK_MONOTONIC, &tStart);

	if (j == 0) {
	    // First time, do random values
	    //srand(time(NULL));
	    srand(1); // seed so we get the same random numbers for each iteration of j
	    for (i = 0; i < NCOUNT; i++) {
		v = rand() % OneMillion;
		rc = tree.insert(myToString(v));
	    }
	} else {
	    // Second time, do ascending values
	    for (i = 0; i < NCOUNT2; i++) {
		rc = tree.insert(myToString(i));
	    }
	}

	clock_gettime(CLOCK_MONOTONIC, &tStop);

	cout << "Tree(" << j << ") took " << getElapsedTime(tStart,tStop) << " ms to insert.\n";
	
	//
	// TIMING isIn
	//
	clock_gettime(CLOCK_MONOTONIC, &tStart);
	//srand(time(NULL));
	srand(1); // seed so we get the same random numbers for each iteration of j

	for (i = 0; i < NCOUNT; i++) {
	    v = rand() % OneMillion;
	    rc = tree.isIn(myToString(v));
	}

	clock_gettime(CLOCK_MONOTONIC, &tStop);

	cout << "Tree(" << j << ") took " << getElapsedTime(tStart,tStop) << " ms to do isIn().\n";

	tree.clear();
    }

    cout << "Do Work - END   ********************\n";
}

//***********************************************************************

int main(int argc, char *argv[]) {
    sAVL myAVL;

    doWork(myAVL);

    return 0;
}
