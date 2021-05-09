//file: graphm.h
//Class graphm class
//Louis Taing
#pragma once
#include "nodedata.h"
using namespace std;


//---------------------------------------------------------------------------
// Graphm class:  
//   --allows user to find the shortest path using dijkstra given a file
//	 --allows user to insert an edge b/w 2 nodes
//	 --allows user to remove an edge b/w 2 nodes
// Implementation and assumptions:
//   -- implemented using Nodes and NodeData 
//---------------------------------------------------------------------------

//global constant
const int MAXNODES = 101;

class GraphM
{
public:
	GraphM();
	~GraphM();
	void buildGraph(ifstream&);
	void insertEdge(int, int, int);
	void removeEdge(int, int);
	void findShortestPath();
	void displayAll();
	void display(int, int);
	//some utility func's may be needed
	void getPathToDisplayAll(int, int);
	void getPathToDisplay(int, int);

private:
	struct TableType {
		bool visited; // whether node has been visited
		int dist; // shortest distance from source known so far
		int path; // previous node in path of min dist
	};
	NodeData data[MAXNODES];
	int C[MAXNODES][MAXNODES]; // Cost array, the adjacency matrix
	int size; // number of nodes in the graph
	TableType T[MAXNODES][MAXNODES]; // stores visited, distance, path
};



