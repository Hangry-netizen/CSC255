/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 4a
*/

#include <iostream>
#include <fstream>

#include "p4.h"

using namespace std;

//******************************************************************************

sBST::sBST(){
    root = NULL;
    treeCount = 0;
}

//******************************************************************************

sBST::~sBST() {
    clear();
}

