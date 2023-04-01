#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "p9b.h"

using namespace std;


main(int argc, char *argv[]) {
    int action, unode, vnode, weight;
    int mytable[40];
    int mytable2[40];
    int count = 0;
    int count2 = 0;
    int i, j, label;
    bool doit;
    bool rc;

    dGraph myGraph(40, true);

    while (cin >> action >> unode >> vnode >> weight) {
	if (vnode >= 0) {
	    // this is an edge record
	    if (action == 0) {
		rc = myGraph.addEdge(unode, vnode, weight);
		cout << "addEdge(" << unode << "," << vnode << "," << weight << ") returned: " << (rc?"True":"False") << endl;
	    } else {
		rc = myGraph.deleteEdge(unode, vnode);
		cout << "deleteEdge(" << unode << "," << vnode << ") returned: " << (rc?"True":"False") << endl;
	    }
	} else {
	    // this is a node creation
	    if (action == 0) {
		rc = myGraph.createV(unode);
		cout << "createV(" << unode << ") returned: " << (rc?"True":"False") << endl;
	    }
	}
	mytable[count++] = unode;
    }
    myGraph.printIt();
    myGraph.printPaths();
    cout << "*** start of bfPrint() output\n";
    for (i = 0; i < count; i++) {
	
	label = mytable[i];
	doit = true;
	for (j = 0; j < count2; j++ ) {
	    if (label == mytable2[j]) {
		doit = false;
		break;
	    }
	}

	if (doit) {
	    mytable2[count2++] = label;
	    cout << "   Printing from " << label << endl;
	    myGraph.bfPrint(label);
	}
    }
    cout << "*** end of bfPrint() output\n";
}
