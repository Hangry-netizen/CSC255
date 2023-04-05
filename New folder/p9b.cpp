/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 9a
*/

#include <iostream>

#include "p9b.h"

using namespace std;

//******************************************************************************
// Joseph Song & Queena Lee
dGraph::dGraph(int n, bool directed) {
    // set up an empty dGraph
    this->n = n;
    this->directed = directed;
    a = new int[n*n];
    labels = new intList[n]; 
    q = new iQ[n];
    clear();
}

//******************************************************************************
// Joseph Song & Queena Lee
dGraph::~dGraph() {
    // delete the array "a"
    if (a != 0) {
        //if array exists, delete the dynamically allocated array
        delete[] a;
        a = NULL;
    }
    delete[] labels;
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
int dGraph::ind(int x, int y) const {
    // return the mapping of x,y to index
    if (directed == false) {
        // use least vertex id first for undirected graphs
        if (y < x) {
            int temp = x;
            x = y;
            y = temp;
        }
    }
    
    return (x*n) + y;
}

//******************************************************************************
// Joseph Song & Queena Lee
int dGraph::labelToVid(int label) const {
    // return the vertex id for the given label
    // return -1 if  no nodes has that label
    return labels->getIndex(label);
}

//******************************************************************************
// Joseph Song & Queena Lee
int dGraph::vidToLabel(int vid) const{
    return labels->readAt(vid);
}

//******************************************************************************
// Joseph Song & Queena Lee
bool dGraph::createV(int label) {
    // create the node labeled by the parameter
    bool rc = false;

    if (!isV(label)) {
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
bool dGraph::addEdge(int uLabel, int vLabel, int weight) {
    bool rc = false;
    bool labelsExist = false;

    if (!(isEdge(uLabel, vLabel)) && weight > 0) {
        // if edge does not exist yet and weight is > 0        
        if (!isV(uLabel) && !isV(vLabel)) {
            // if both vertices do not exist yet
            if ((n - vCount) >= 2) {
                // if there is space, create vertices
                createV(uLabel);
                createV(vLabel);
                labelsExist = true;
            }
        } else if (!isV(uLabel) || !isV(vLabel))  {
            // if one of the two vertices does not exist yet
            if ((n - vCount) >= 1) {
                // if there is space, create vertice for the non-existing label
                createV(uLabel);
                createV(vLabel);
                labelsExist = true;
            }
        } else {
            labelsExist = true;
        }

        if (labelsExist) {
            // if labels have been created, create an edge with the given weight
            int uVid = labelToVid(uLabel);
            int vVid = labelToVid(vLabel);
    
            a[ind(uVid, vVid)] = weight;
            rc = true;
            eCount++;
        }
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool dGraph::deleteEdge(int uLabel, int vLabel) {
    // delete the edge if the edge exists
    bool rc = isEdge(uLabel, vLabel);

    if (rc) {
        // if edge exists, delete the edge
        int uVid = labelToVid(uLabel);
        int vVid = labelToVid(vLabel);
        a[ind(uVid, vVid)] = 0;
        eCount--;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
void dGraph::clear() {
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
bool dGraph::isEdge(int uLabel, int vLabel) const {
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
bool dGraph::isV(int label) const {
    // return true if there is a node labeled by label
    return labels->getIndex(label) != -1;
}

//******************************************************************************
// Joseph Song & Queena Lee
int dGraph::inDegree(int label) const {
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
int dGraph::outDegree(int label) const {
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
int dGraph::sizeV() const {
    // return the number of nodes actually used
    return vCount;
}

//******************************************************************************
// Joseph Song & Queena Lee
int dGraph::sizeE() const {
    // return the number of edges in the dGraph
    return eCount;
}

//******************************************************************************
// Joseph Song & Queena Lee
void dGraph::printIt() const {
    int r, c;

    cout << "dGraph info:\n";
    cout << "  dGraph size = " << n << endl;
    cout << "  vCount = " << sizeV() << endl;
    cout << "  eCount = " << sizeE() << endl;
    cout << "\nGraph contents:\n";
    for (r = 0; r < sizeV(); r++) {
	cout << "  Node(" << r << "," << labels->readAt(r) << "):";
	for (c = 0; c < sizeV(); c++) {
	    cout << " " << a[ind(r,c)];
	}
	cout << endl;
    }

    cout << "Degree table (in, out)\n";

    for (r = 0; r < sizeV(); r++) {
	cout << "  Node(" << r << "," << labels->readAt(r) << "):";
	cout << " " << inDegree(labels->readAt(r)) << ", " << outDegree(labels->readAt(r)) << endl;
    }
}


//******************************************************************************
// Joseph Song & Queena Lee
void dGraph::bfPrint(int label) const {
    // print a breadth-frist traversal of the graph, starting at the given node
    bool rc = false;
    int item = 0;

    bool* visited = new bool[vCount];
    
    // initialize each entry in visited with false
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    if (isV(label)) {
        // if the given starting node exists, enqueue and print node
        q->enq(label);
        cout << "       Item " << item++ << " is" << "(" << labelToVid(label) << ",";
        cout << label << ")" << endl;
    }

    while(q->count() > 0) {
        // if queue is not empty
        int v;
        q->deq(v);

        if (!visited[labelToVid(v)]) {
            // visit each neighbor of v that has not been visited
            visited[labelToVid(v)] = true;
            for (int i = 0; i < vCount; i++) {
                // iterate through each vertex
                if (isEdge(v, vidToLabel(i)) && !visited[i]) {
                    // if vertex is a neighbor of v and has not been visited, 
                    // enqueue vertex, mark vertex as visited, and print vertex
                    q->enq(vidToLabel(i));
                    cout << "       Item " << item++ << " is" << "(" << i << ",";
                    cout << vidToLabel(i) << ")" << endl;
                }
            }
        }
    }

}

//******************************************************************************
// Joseph Song & Queena Lee
bool dGraph::isPath(int ulabel, int vlabel) const {    
    // perform a breadth-frist traversal of the graph, starting at the given node
    bool rc = false;

    bool* visited = new bool[vCount];

    // initialize each entry in visited with false
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    if (isV(ulabel)) {
        // if the given starting node exists, enqueue the node
        q->enq(ulabel);
    }

    while(q->count() > 0) {
        // if queue is not empty
        int v;
        q->deq(v);

        if (!visited[labelToVid(v)]) {
            // visit each neighbor of v that has not been visited
            visited[labelToVid(v)] = true;
            for (int i = 0; i < vCount; i++) {
                // iterate through each vertex
                if (isEdge(v, vidToLabel(i))) {
                    // if vertex is a neighbor of v and has not been visited, 
                    // enqueue vertex
                    if (!visited[i]) {
                        q->enq(vidToLabel(i));
                    } 
                }
            }
        }

        if (visited[labelToVid(vlabel)]) {
            // if vlabel has been visited
            // it means a path has been found fron ulabel to vlabel
            // therefore, set rc to true and break the loop
            rc = true;
        }
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
void dGraph::printPaths() const{
    for (int i = 0; i < vCount; i++) {
        for (int j = 0; j < vCount; j++) {
            if (isPath(vidToLabel(i), vidToLabel(j))) {
                cout << vidToLabel(i) << " does have a path to ";
                cout << vidToLabel(j) << endl;
            } else {
                cout << vidToLabel(i) << " does not have a path to ";
                cout << vidToLabel(j) << endl;
            }
        }
    }
}