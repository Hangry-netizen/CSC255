#include <iostream>   // gets cin, cout, cerr
#include <fstream>    // gets file functions of open and close
#include <string.h>   // gets the string type, which is part of std namespace

#include "p2.h"

using namespace std;

//******************************************************************************

void doWork(string dataName) {
    int i;
    int val;
    bool rc;
    ifstream dataFile;
    string action, text;
    int index;

    stringLinkedList *myList = new stringLinkedList();

    cout << "Do Work - START ********************\n";

    dataFile.open(dataName);

    if (!dataFile) {
	cerr << "File could not be opened: " << dataName << endl;
	exit(1);
    }

    cout << "START ********************\n";

    cout << "The list has " << myList->count() << " items, which are:\n";
    myList->printIt();

    cout << "\nprocessing the input file ********************\n";

    while (dataFile >> action >> index >> text) {
	if (action == "insert") {
	    cout << "insert " << text << " got ";
	    cout << (myList->insert(text) ? "true" : "false") << endl;
	} else if (action == "insertAt") {
	    cout << "insertAt " << index << "," << text << " got ";
	    cout << (myList->insertAt(index, text) ? "true" : "false") << endl;
	} else if (action == "add") {
	    cout << "add of " << text << " got ";
	    cout << (myList->add(text) ? "true" : "false") << endl;
	} else if (action == "deleteAt") {
	    cout << "deleteAt " << index << " got ";
	    if (myList->deleteAt(index, text)) {
		cout << "true and " << text << endl;
	    } else {
		cout << "false and " << text << endl;
	    }
	} else if (action == "readAt") {
	    cout << "readAt " << index << " got ";
	    if (myList->readAt(index, text)) {
		cout << "true and " << text << endl;
	    } else {
		cout << "false and " << text << endl;
	    }
	} else if (action == "getIndex") {
	    val = myList->getIndex(text);
	    cout << "getIndex " << text << " got " << val << endl;
	} else if (action == "printIt") {
	    myList->printIt();
	} else if (action == "clear") {
	    myList->clear();
	    cout << "List was cleared\n";
	} else {
	    cerr << "Invalid command: " << action << endl;
	}
    }

    delete myList;
}

//******************************************************************************

int main(int argc, char *argv[]) {
    int rc = 0;

    if (argc == 2) {
	doWork(argv[1]);
    } else {
	cerr << "No input file given.\n";
	rc = -1;
    }

    return rc;
}
