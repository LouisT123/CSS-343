//file: graphl.cpp
//Class graphl implementations from graphl.h
//Louis Taing

#include "graphl.h"
#include <climits>
#include <iomanip>

using namespace std;
//-----------------------------------------------------------------------------
//constructor
GraphL::GraphL()
{
	//initialize
	for (int i = 1; i < MAXNODES_L; i++) 
	{
		list[i].visited = false;
		list[i].edgeHead = NULL;
	}
	size = 0;
}
//-----------------------------------------------------------------------------
//destructor
GraphL::~GraphL()																
{
	if (size > 0)
	{
		for (int i = 1; i <= size; i++) 
		{
			EdgeNode* temp = list[i].edgeHead; 
			//while head not null, swap and delete
			while (temp != NULL) {
				EdgeNode* next = temp->nextEdge;  
				delete temp;
				temp = next;
			}
			//reinitialize
			list[i].edgeHead = NULL;
			list[i].visited = false;
		}
		size = 0;
	}
}
//-----------------------------------------------------------------------------
//builds up graph node information and adjacency list of edges between each
//node reading from a data file.
void GraphL::buildGraph(ifstream& file)											
{
	int from = 0;
	int to = 0;

	//extract size of graph
	file >> size;
	//node name
	string nodeName = "";
	//read line
	getline(file, nodeName);
	//for size of data arr, name each node
	for (size_t i = 1; i <= size; i++)
	{
		//basically calls getline in nodedata.cpp
		list[i].data.setData(file);
	}

	//grab rest of data
	while (file >> from >> to)
	{
		if (from == 0)
		{
			break; //no more lines left
		}
		//insert
		insertEdge(from, to);
	}
}
//-----------------------------------------------------------------------------
//insert an edge b/w 2 given nodes
void GraphL::insertEdge(int from, int to)										
{
	if (from > size)
	{
		return;
	}
	if (from <= 0)
	{
		return;
	}
	if (to <= 0)
	{
		return;
	}
	EdgeNode* insert = new EdgeNode;
	insert->adjGraphNode = to;
	insert->nextEdge = list[from].edgeHead;
	list[from].edgeHead = insert;
}
//-----------------------------------------------------------------------------
//Makes a depth-first search and displays each node in depth-first order
void GraphL::depthFirstSearch()
{
	cout << endl << "Depth First Ordering: ";
	for (size_t i = 1; i < size; i++)
	{
		if (list[i].visited == false)
		{
			dfshelper(i);
		}
	}
}
//-----------------------------------------------------------------------------
//helper, called in depthFirstSearch()
void GraphL::dfshelper(int i)
{				
	//set to visited
	list[i].visited = true;															

	//print source 
	cout << i << " ";

	// set head
	EdgeNode* temp = list[i].edgeHead;

	while (temp != NULL )
	{	//if adj node not visited
		if (!list[temp->adjGraphNode].visited)
		{
			//recursion
			dfshelper(temp->adjGraphNode); 
		}
			//next edge
		temp = temp->nextEdge;
	}
}
//-----------------------------------------------------------------------------
//Displays each node information and edge in the graph
void GraphL::displayGraph()
{
	EdgeNode* node;																
	cout << endl << endl <<  "Graph: " << endl;
	for (int i = 1; i <= size; i++) 
	{
		//print out node and data
		cout << "Node" << i << "      ";
		cout << setw(9) << list[i].data << endl << endl; 

		//if not at end of list
		if (list[i].edgeHead != NULL) 
		{ 
			node = list[i].edgeHead; 
			
			while (node != NULL) 
			{ 
				cout << setw(7) << "edge " << i << " "; 
				//get adjacent node
				cout << node->adjGraphNode << endl; 
				//next edge
				node = node->nextEdge; 
			}
		}
	}
	cout << endl;
}