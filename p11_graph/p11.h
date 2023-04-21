/*
* Joseph Song
* Queena Lee
* CSC255 Spring 2023
* Assignment: Program 11
*/

#ifndef __P11_H
#define __P11_H

#include <string>
#include "p1.h"
#include "iq.h"

class Graph {
    private:
        // The array for the graph; the size will be n*n
        int *a;

        // Stores the labels of the edge; size will be n
        intList *labels; 

        // Queue
        iQ *q;

        // an array of size n
        // that holds distances used in performing Dijkstra
        int *lambda;

        // an array of size n
        // used to track with set, X or Y, that a given node is in
        int *set;

        int const INFINITE = 1000000;

        // Used with "set", this will mark a node in set X
        int const X = 0;

        // Used with "set", this will mark a node in set Y
        int const Y = 1;

        // Memorializes the dimensions of the graph matrix
        int n;

        // Tracks the number of nodes in the graph
        int vCount;

        // Tracks the number of edges in the graph
        int eCount;
        
        // Remembers whether the graph is directed or not
        bool directed;

        // Populates lambda with the distance from node s to all other nodes
        // note that s is an index, not a label
        void dijkstra(int s);

        // Returns true with minV set to the minimum value node in Y
        // if at least one node is in Y
        // Otherwise, returns false with minV set to -1 if no node is in Y
        bool minLambdaY(int &minY);

        
        // Returns the mapping of x,y to index
        // uses least vertex id first for undirected graphs
        int ind(int x, int y) const;

        // Returns the vertex id for the given label
        // returns -1 if no nodes has that label
        int labelToVid(int label) const;

        // Returns the label for the given vertex id
        // returns -1 if no nodes has that vertex id
        int vidToLabel(int vid) const;

        // Returns true if a directed graph is cyclic
        // it need not verify to see if the graph is directed
        bool isCyclicDirected() const;

        // Returns true if an undirected graph is cyclic
        // it need not verify to see if the graph is undirected
        bool isCyclicUndirected() const;
        
    public:
        // Sets up the empty graph
        Graph(int n = 100, bool directed = true);

        // Deletes the array "a"
        ~Graph();

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
        bool deleteEdge(int uLabel, int vLabel, int &weight);

        // Returns true if sLabel and dLabel are both valid labels of real nodes
        // it will also return the distance from node sLabel to node dLabel
        // if either label is not a valid node, distance will be set to -1
        bool dijkstra (int sLabel, int dLabel, int &distance);

        // Causes the graph to be reset ot its original state
        // with no vertices or edges
        void clear();

        // Returns true if the edge exists
        // returns false if the node labels are not both assigned to a node
        // or if the edge does not exist (weight == 0)
        bool isEdge(int uLabel, int vLabel) const;

        // Return true if there is a node labeled by label
        bool isV(int label) const;

        // Returns the inD of the node
        // returns -1 if the graph is undirected or the node does not exist
        int inDegree(int label) const;

        // Returns the outD of the node
        // returns -1 if the graph is undirected or the node does not exist
        int outDegree(int label) const;

        // Returns the degree of the node
        // returns -1 if the graph is not undirected or the node does not exist
        int degree(int label) const;

        // Returns the number of nodes actually used, vCount
        int sizeV() const;

        // Returns the number of edges in the graph, eCount
        int sizeE() const;

        // Returns whether the graph is cyclic
        bool isCyclic() const;

        // Prints the graph; see sample output for proper format
        void printIt() const;

        // Prints the breadth-first search of the graph
        // starting from the given label
        void bfPrint(int label) const;

        // Using breadth-first search, determines if u has a path to v
        bool isPath(int uLabel, int vLabel) const;

        // Prints all paths in the graph
        void printPaths() const;
};

#endif