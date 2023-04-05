#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "p9a.h"

using namespace std;


main(int argc, char *argv[]) {
    int unode, vnode, weight;
    Graph myGraph(40, true);

    while (cin >> unode >> vnode >> weight) {
	if (vnode >= 0) {
	    // this is an edge record
	    myGraph.addEdge(unode, vnode, weight);
	} else {
	    // this is a node creation
	    myGraph.createV(unode);
	}
    }
    myGraph.printIt();

}
