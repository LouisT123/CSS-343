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
	//constructor
	GraphM();
	//destructor
	~GraphM();
	//builds up graph node information and adjacency matrix of edges between each
	//node reading from a data file.
	void buildGraph(ifstream&);
	//insert an edge b/w 2 given nodes
	void insertEdge(int, int, int);
	//remove an edge b/w 2 given nodes
	void removeEdge(int, int);
	//using dijkstra to find shortest path
	void findShortestPath();
	//display entire graph
	void displayAll();
	//helper for display all func (gives path)
	void getPathToDisplayAll(int, int);
	//uses couts to display the shortest distance with path info between the 
	//fromNode to toNode.
	void display(int, int); 
	//helper for display and display all func (gives data)
	void getDataToDisplay(int, int);

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



