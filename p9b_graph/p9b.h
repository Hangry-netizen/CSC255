/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 9a
*/

#ifndef __P9a_H
#define __P9a_H

#include <string>
#include "p1.h"
#include "iq.h"

class dGraph {
    private:
        // The array for the graph; the size will be n*n
        int *a;

        // Stores the labels of the edge; size will be n
        intList *labels; 

        iQ *q;

        // Memorializes the dimensions of the graph matrix
        int n;

        // Tracks the number of nodes in the graph
        int vCount;

        // Tracks the number of edges in the graph
        int eCount;
        
        // Remembers whether the graph is directed or not
        bool directed;
        
        // Returns the mapping of x,y to index
        // uses least vertex id first for undirected grapghs
        int ind(int x, int y) const;

        // Returns the vertex id for the given label
        // returns -1 if no nodes has that label
        int labelToVid(int label) const;

        int vidToLabel(int vid) const;

    public:
        // Sets up the empty graph
        dGraph(int n = 100, bool directed = true);

        // Deletes the array "a"
        ~dGraph();

        // Creates the node labeled by the parameter
        // returns true if the label is not already used and
        // and there is a label table entry left to be allocated to the label
        // otherwise, returns false
        bool createV(int label);

        // Creates the edge with the given weight. Weight must be > 0.
        // returns true if edge is added
        // otherwise, returns false if nodes can't be created, the edge
        // already exists, or weight is not a positive, non-zero integer
        bool addEdge(int uLabel, int vLabel, int weight);

        // Deletes the edge, if the edge had been set and decrements eCount
        // returns true if it deletes it
        // returns false if the edge was already deleted
        // returns false if the labels didn't match existing nodes
        bool deleteEdge(int uLabel, int vLabel);

        // Causes the graph to be reset ot its original state
        // with no vertices or edges
        void clear();

        // Returns true if the edge exists
        // returns false if the node labels are not both assigned to a node
        // or if the edge does not exist (weight == 0)
        bool isEdge(int uLabel, int vLabel) const;

        // Return true if there is a node labeled by label
        bool isV(int label) const;

        // Return inD of the node; -1 if the node does not exist
        int inDegree(int label) const;

        // Return outD of the node; -1 if the node does not exist
        int outDegree(int label) const;

        // Returns the number of nodes actually used, vCount
        int sizeV() const;

        // Returns the number of edges in the graph, eCount
        int sizeE() const;

        // Prints the graph; see sample output for proper format
        void printIt() const;

        void bfPrint(int label) const;

        bool isPath(int ulabel, int vlabel) const;

        void printPaths() const;
};

#endif