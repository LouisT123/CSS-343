//file: graphl.h
//Class graphl class
//Louis Taing
#pragma once

#include "nodedata.h"
#include <iostream>
using namespace std;


//---------------------------------------------------------------------------
// Graphl class:  
//   --allows user to get depth first search order of a given file
// Implementation and assumptions:
//   -- implemented using Nodes and NodeData 
//---------------------------------------------------------------------------

//global constant
const int MAXNODES_L = 101;

class GraphL
{
public:
	//constructor
	GraphL();
	//destructor
	~GraphL();
	//builds up graph node information and adjacency matrix of edges between each
	//node reading from a data file.
	void buildGraph(ifstream&);
	//Makes a depth-first search and displays each node in depth-first order
	void depthFirstSearch();
	//helper for dfs();
	void dfshelper(int);
	//Displays each node information and edge in the graph
	void displayGraph();														
	//insert an edge b/w 2 given nodes
	void insertEdge(int, int);

private:

	struct EdgeNode; // forward reference for the compiler
	struct GraphNode { // structs used for simplicity, use classes if desired
		EdgeNode* edgeHead; // head of the list of edges
		NodeData data; // data information about each node						
		bool visited;
	};
	struct EdgeNode {
		int adjGraphNode; // subscript of the adjacent graph node
		EdgeNode* nextEdge;
	};
	GraphNode list[MAXNODES_L];
	int size;
};



