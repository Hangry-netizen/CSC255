#include <iostream>   // gets cin, cout, cerr
#include <fstream>    // gets file functions of open and close
#include <string.h>   // gets the string type, which is part of std namespace

#include "p4.h"

//******************************************************************************

using namespace std;

//******************************************************************************

void doWork(sBST &myTree, string dataName, string removeName,
	string isInName) {

    int i, j;
    string text;
    int deleteCount;
    bool rc;
    ifstream dataFile, removeFile, isInFile;

    cout << "Do Work - START ********************\n";

    dataFile.open(dataName);

    if (!dataFile) {
	cerr << "File could not be opened: " << dataName << endl;
	exit(1);
    }

    removeFile.open(removeName);

    if (!removeFile) {
	cerr << "File could not be opened: " << removeName << endl;
	exit(1);
    }

    isInFile.open(isInName);

    if (!isInFile) {
	cerr << "File could not be opened: " << isInName << endl;
	exit(1);
    }

    cout << "Inserting text from: " << dataName << endl;
    while (dataFile >> text) {
	if (!myTree.insert(text)) {
	    if (myTree.count() < 50) {
		cout << "Text not inserted:  " << text << endl;
	    }
	}
    }
    
    cout << "Tree count is " << myTree.count() << endl;

    if (myTree.count() < 100) {
	cout << "Tree contents are: \n";
	myTree.printIt();
    }

    deleteCount = 0;

    cout << "Removing text from: " << removeName << endl;
    while (removeFile >> text) {
	if (myTree.remove(text)) {
	    cout << text << " was removed\n";
	    deleteCount++;
	} else {
	    cout << text << " was NOT removed\n";
	}
    }

    cout << "\nDelete Count is " << deleteCount << endl;
    cout << "Tree count is " << myTree.count() << endl;

    if (myTree.count() < 100) {
	cout << "Tree contents are: \n";
	myTree.printIt();
    }

    cout << endl;

    cout << "Checing for text from: " << isInName << endl;

    while (isInFile >> text) {
	if (myTree.isIn(text)) {
	    cout << "isIn reports this is in the list: " << text << endl;
	} else {
	    cout << "isIn reports this is NOT in the list: " << text << endl;
	}
    }

    myTree.clear();

    cout << "\nThe cleared tree status:  count = " << myTree.count() <<endl;

    if (myTree.count() < 100) {
	cout << "The cleared tree contents follow:\n";
	myTree.printIt();
    }

    dataFile.close();
    removeFile.close();
    isInFile.close();
    cout << "Do Work - END   ********************\n";
}

//******************************************************************************

int main(int argc, char *argv[]) {
    sBST theTree;

    if (argc == 4) {
	doWork(theTree, argv[1], argv[2], argv[3]);
    }

    return 0;
}
