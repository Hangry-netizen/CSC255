/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 11
*/

#include <iostream>
#include <iomanip>

#include "p11.h"

using namespace std;

//******************************************************************************
// Joseph Song & Queena Lee
Graph::Graph(int n, bool directed) {
    // set up an empty Graph
    this->n = n;
    this->directed = directed;
    a = new int[n*n];
    labels = new intList(n); 
    q = new iQ(n);
    lambda = new int[n];
    set = new int[n];
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
    delete labels;
    delete q;
    delete [] lambda;
    delete [] set;
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
    int rc;

    if (directed == true) {
        rc = (x*n) + y;
    } else {
        // for undirected graphs, use least vertex id first
        rc = x < y ? (x*n) + y : (y*n) + x;
    }
    
    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
int Graph::labelToVid(int label) const {
    // return the vertex id for the given label
    // return -1 if  no nodes has that label
    return labels->getIndex(label);
}

//******************************************************************************
// Joseph Song & Queena Lee
int Graph::vidToLabel(int vid) const{
    return labels->readAt(vid);
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::createV(int label) {
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
bool Graph::addEdge(int uLabel, int vLabel, int weight) {
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
bool Graph::deleteEdge(int uLabel, int vLabel, int &weight) {
    // delete the edge if the edge exists
    bool rc = isEdge(uLabel, vLabel);
    weight = -1;

    if (rc) {
        // if edge exists, delete the edge
        int uVid = labelToVid(uLabel);
        int vVid = labelToVid(vLabel);
        weight = a[ind(uVid, vVid)];
        a[ind(uVid, vVid)] = 0;
        eCount--;
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
void Graph::dijkstra(int s) {
    // populate lambda with the distances from node s to all other nodes
    // note that s is an index, not a label
    int w;
    int v;

    // initialize lambda and set arrays for dijkstra
    for (int i = 0; i < vCount; i++) {
        // set each node to set Y
        set[i] = Y;
        w = a[(ind(s,i))];
        // if path exists from source node to node
        // set the weight of the path in lambda 
        // otherswise, set lambda to infinite
        lambda[i] = w ? w : INFINITE;
    }

    // initialize source node in lambda and set
    lambda[s] = 0;
    set[s] = X;

    while(minLambdaY(v)) {
        // while there are still nodes in Y, set it to set X
        set[v] = X;
        for (int i = 0; i < vCount; i++) {
            // find the node's adjacencies and compare if found path 
            // to adjacency node is shorter than adjacency's existing path
            if ((w = a[ind(v,i)]) && set[i]==Y) {
                // set the shorter path to adjacency node in lambda
                lambda[i] = min(lambda[i],(w + lambda[v]));
            }
        }
    }
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::minLambdaY(int &minV) {
    // return true with minV set to the index of the minValue in Y
    // if at least one node is in Y
    // otherwise, return false with minV set to -1 if no node is in Y
    bool rc = false;
    int min = INFINITE;


    for (int i = 0; i < vCount; i++) {
        // for each node in graph
        if (set[i] == Y) {
            // if node(s) exist in set Y
            // set the index of the node with minValue in set Y to minV
            rc = true;
            if (min >= lambda[i]) {
                minV = i;
                min = lambda[i];
            }
        }
    }

    return rc;
}


//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::dijkstra(int sLabel, int dLabel, int &distance) {
    // return true and the distance from sLabel to dLabel if both labels exist
    // otherwise, return false and distance as -1
    bool rc = false;
    distance = -1;

    if (isV(sLabel) && isV(dLabel)) {
        // if both labels exist
        // perform dijkstra to get the shortest paths to each node on the graph
        rc = true;
        dijkstra(labelToVid(sLabel));
        distance = lambda[labelToVid(dLabel)];
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
    // return true if there is a node labeled by label
    return labels->getIndex(label) != -1;
}

//******************************************************************************
// Joseph Song & Queena Lee
int Graph::inDegree(int label) const {
    // return inD of the node
    // return -1 if the graph is undirected or the node does not exist
    int rc = -1;

    if (directed && isV(label)) {
        // if graph is direct and vertice exists
        rc = 0;
        for (int i = 0; i < n; i++) {
            // for each column of the vertice
            if (a[ind(i,labelToVid(label))] > 0) {
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
    // return outD of the node
    // return -1 if the graph is undirected or the node does not exist
    int rc = -1;

    if (directed && isV(label)) {
        // if graph is direct and vertice exists
        rc = 0;
        for (int i = 0; i < vCount; i++) {
            // for each row of the vertice
            if (a[ind(labelToVid(label),i)] > 0) {
                // if an edge exists, increment its outDegree
                rc++;
            }
        }
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
int Graph::degree(int label) const {
    // return the degree of the node
    // return -1 if the graph is not undirected or the node does not exist

    int rc = -1;
    int vid = labelToVid(label);

    if (!directed && isV(label)) {
        // if the graph is undirected and the node exists
        rc = 0;
        for (int i = 0; i < vCount; i++) {
            if (a[ind(vid,i)] > 0) {
                // if an edge exists, increment its degree 
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
    // return the number of edges in the Graph
    return eCount;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::isCyclicDirected() {
    // return true if a directed graph is cyclic
    // otherwise, return false
    bool rc = false;
    int label;

    for (int i = 0; i < vCount; i++) {
        // for each node in the graph
        label = vidToLabel(i);
        if (isPath(label,label)) {
            // if node has a path to itself, return true
            rc = true;
            break;
        }
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::isCyclicUndirected() {
    // return true if a undirected graph is cyclic
    // otherwise, return false
    bool rc = false;
    int uLabel, vLabel, weight;

    for (int i = 0; i < vCount; i++) {
        uLabel = vidToLabel(i);
        for (int j = 0; j < vCount; j++) {
            vLabel = vidToLabel(j);
            if (isEdge(uLabel,vLabel)) {
                deleteEdge(uLabel,vLabel,weight);
                rc = isPath(vLabel,uLabel) ? true : false;
                addEdge(uLabel,vLabel,weight);
            }
            if (rc) {
                break;
            }
        }
        if (rc) {
            break;
        }
    }

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::isCyclic() {
    // return whether the graph is cyclic
    return directed ? isCyclicDirected() : isCyclicUndirected();
}

//******************************************************************************
// Joseph Song & Queena Lee
void Graph::printIt() const {
    int r, c;

    cout << "Graph info:\n";
    cout << "  Graph size = " << n << endl;
    cout << "  vCount = " << sizeV() << endl;
    cout << "  eCount = " << sizeE() << endl;
    cout << "\nGraph contents:\n";
    for (r = 0; r < sizeV(); r++) {
        cout << "  Node(" << r << "," << labels->readAt(r) << "):";
        for (c = 0; c < sizeV(); c++) {
            cout << setw(3) << a[(r*n)+c];
        }
	    cout << endl;
    }

    cout << "Degree table (normal, in, out)\n";

    for (r = 0; r < sizeV(); r++) {
	    cout << "  Node(" << r << "," << labels->readAt(r) << "):";
        cout << setw(6) << degree(labels->readAt(r)) << ", ";
        cout << inDegree(labels->readAt(r)) << ", ";
        cout << outDegree(labels->readAt(r)) << endl;
    }
}


//******************************************************************************
// Joseph Song & Queena Lee
void Graph::bfPrint(int label) const {
    // print a breadth-frist traversal of the graph, starting at the given node
    bool rc = false;
    int vid = labelToVid(label);
    int item = 0;

    bool* visited = new bool[vCount];
    
    // initialize each entry in visited with false
    for (int i = 0; i < vCount; i++) {
        visited[i] = false;
    }
    
    // ensure that q is clear
    q->clear();

    if (isV(label)) {
        // if the given starting node exists, mark it visited, 
        // enqueue the node and print node
        q->enq(vid);
        visited[vid] = true;
    }

    while(q->deq(vid)) {
        // print v
        cout << "       Item " << item++ << " is" << "(" << vid << ",";
        cout << vidToLabel(vid) << ")" << endl;
        for (int i = 0; i < vCount; i++) {
            if (isEdge(vidToLabel(vid), vidToLabel(i)) && !visited[i]) {
                // visit each neighbor of v that has not been visited,
                // enqueue vertex and mark vertex as visited
                q->enq(i);
                visited[i] = true;
            }
        }
    }

    delete[] visited;
}

//******************************************************************************
// Joseph Song & Queena Lee
bool Graph::isPath(int uLabel, int vLabel) const {    
    // perform a breadth-frist traversal of the graph, starting at the given node
    bool rc = false;
    int vid = labelToVid(uLabel);

    bool* visited = new bool[vCount];

    // initialize each entry in visited with false
    for (int i = 0; i < vCount; i++) {
        visited[i] = false;
    }

    q->clear();
    if (isV(uLabel)) {
        // if the given starting node exists, enqueue the node
        q->enq(vid);
    }

    while(q->deq(vid)) {
        if (visited[labelToVid(vLabel)]) {
            // if vlabel has been visited, there is a path from u to v
            rc = true;
            break;
        }

        for (int i = 0; i < vCount; i++) {
            if (isEdge(vidToLabel(vid), vidToLabel(i)) && !visited[i]) {
                // visit each neighbor of v that has not been visited
                q->enq(i);
                visited[i] = true;
            }
        }
    }
    
    delete[] visited;

    return rc;
}

//******************************************************************************
// Joseph Song & Queena Lee
void Graph::printPaths() const{
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