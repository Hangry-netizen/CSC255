/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 9a
*/

#include <iostream>

#include "p9a.h"

using namespace std;

//******************************************************************************
// Joseph Song & Queena Lee
Graph::Graph(int n, bool directed) {
    // set up an empty graph
    this->n = n;
    this->directed = directed;
    a = new int[n*n];
    labels = new intList[n]; 
    clear();
}

//******************************************************************************
// Joseph Song & Queena Lee
Graph::~Graph() {
    // delete the array "a"
    if (a != 0) {
        //if array exists, delete the dynamically allocated array
        delete[] a;
        a = NULL;
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
int min (int x, int y) {
    // return the min value between x and y
    int rc = x;

    if (y < x) {
        rc = y;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
int max(int x, int y) {
    // return the max value between x and y
    int rc = x;

    if (y > x) {
        rc = y;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
int Graph::ind(int x, int y) const {
    // return the mapping of x,y to index
    if (directed == false) {
        // use least vertex id first for undirected graphs
        if (y == min(x,y)) {
            int temp = x;
            x = y;
            y = temp;
        }
    }
    
    return (x*n) + y;
}

//******************************************************************************
// Joseph Song & Queena Lee
int Graph::labelToVid(int label) const {
    // return the vertex id for the given label
    // return -1 if  no nodes has that label
    return labels->find(label);
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::createV(int label) {
    // create the node labeled by the parameter
    bool rc = isV(label);

    if (!rc) {
        // if node is not already used
        rc = labels->add(label);

        if (rc) {
            // if there is label table entry left to be allocated to the label
            vCount++;
        }
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::addEdge(int uLabel, int vLabel, int weight) {
    bool rc = false;

    if (!(isEdge(uLabel, vLabel)) && weight > 0) {
        // if edge does not exist yet and weight is > 0        
        if (!isV(uLabel) && !isV(vLabel)) {
            // if both vertices do not exist yet
            if ((n - vCount) >= 2) {
                // if there is space, create vertices
                createV(uLabel);
                createV(vLabel);
            }
        } else if (!isV(uLabel) || !isV(vLabel))  {
            // if one of the two vertices does not exist yet
            if ((n - vCount) >= 1) {
                // if there is space, create vertice for the non-existing label
                if (!(isV(uLabel))) {
                    createV(uLabel);
                } else {
                    createV(vLabel);
                }
            }
        }

        // create an edge with the given weight
        int uVid = labelToVid(uLabel);
        int vVid = labelToVid(vLabel);

        a[ind(uVid, vVid)] = weight;
        rc = true;
        eCount++;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::deleteEdge(int uLabel, int vLabel) {
    // delete the edge if the edge exists
    bool rc = isEdge(uLabel, vLabel);

    int uVid = labelToVid(uLabel);
    int vVid = labelToVid(vLabel);

    if (rc) {
        // if edge exists, delete the edge
        a[ind(uVid, vVid)] = 0;
        eCount--;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
void Graph::clear() {
    // cause the grapgh to be reset to its original state
    vCount = 0;
    eCount = 0;
    
    for (int i = 0; i < n*n; i++) {
        // empty the vertices matrix
        a[i] = 0;
    }

    // empty the labels array
    labels->clear();
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::isEdge(int uLabel, int vLabel) const {
    // return true if the edge exist
    bool rc = false;
    int uVid = labelToVid(uLabel);
    int vVid = labelToVid(vLabel);
    
    if (uVid >= 0 && vVid >= 0) {
        // if vertices exist
        if (a[ind(uVid, vVid)] > 0) {
            // if edge exists
            rc = true;
        }
    }
    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::isV(int label) const {
    // return true if there is a node labled by label
    bool rc = false;

    if (labels->find(label) != -1) {
        // if label exist in labels
        rc = true;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
int Graph::inDegree(int label) const {
    // return inD of the node; -1 if the node does not exist
    int rc = -1;

    int vid = labelToVid(label);

    if (vid != -1) {
        // if vertice exists
        rc = 0;
        for (int i = 0; i < n; i++) {
            // for each column of the vertice
            if (a[ind(i,vid)] > 0) {
                // if an edge exist, increment its inDegree
                rc++;
            }
        }
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
int Graph::outDegree(int label) const {
    // return outD of the node; -1 if the node does not exist
    int rc = -1;

    int vid = labelToVid(label);

    if (vid != -1) {
        // if vertice exist
        rc = 0;
        for (int i = 0; i < n; i++) {
            // for each row of the vertice
            if (a[ind(vid,i)] > 0) {
                // if an edge exist, increment its outDegree
                rc++;
            }
        }
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
int Graph::sizeV() const {
    // return the number of nodes actually used
    return vCount;
}

//******************************************************************************
// Joseph Song & Queena Lee
int Graph::sizeE() const {
    // return the number of edges in the graph
    return eCount;
}

//******************************************************************************
// Joseph Song & Queena Lee
void Graph::printIt() const {
    // print the graph
    int r, c;

    cout << "Graph info:\n";
    cout << "  Graph size = " << n << endl;
    cout << "  vCount = " << vCount << endl;
    cout << "  eCount = " << eCount << endl;
    cout << "\nGraph contents:\n";
   
    for (r = 0; r < vCount; r++) {
        // for each row of the vertices, print the vid and label of the node
        cout << "  Node(" << r << "," << labels->readAt(r) << "):";
        for (c = 0; c < vCount; c++) {
            // for each column of the current vertex,
            // print the weight of the edges
            cout << " " << a[ind(r,c)];
        }
        cout << endl;
    }

    cout << "Degree table (in, out)\n";

    for (r = 0; r < vCount; r++) {
        // for each vertex, print its inDegree and outDegree
	    cout << "  Node(" << r << "," << labels->readAt(r) << "):";
	    cout << " " << inDegree(labels->readAt(r)) << ", ";
        cout << outDegree(labels->readAt(r)) << endl;
    }
}