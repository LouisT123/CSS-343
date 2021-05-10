//file: graphm.cpp
//Class graphm implementations from graphm.h
//Louis Taing

#include "graphm.h"
#include <climits>
#include <iomanip>

//-----------------------------------------------------------------------------
//constructor
GraphM::GraphM()
{
	size = 0;  //amount of nodes is 0
	//initialize tables C and T (nested for loop for each ordered pair)
	for (size_t i = 0; i < MAXNODES; i++)
	{
		for (size_t j = 0; j < MAXNODES; j++)
		{
			C[i][j] = INT_MAX;				
			T[i][j].visited = false;		
			T[i][j].path = 0;				
			T[i][j].dist = INT_MAX;				
		}
	}

}
//-----------------------------------------------------------------------------
//destructor
GraphM::~GraphM()
{
}
//-----------------------------------------------------------------------------
//builds up graph node information and adjacency matrix of edges between each
//node reading from a data file.
void GraphM::buildGraph(ifstream& file)
{
	int from = 0;
	int to = 0;
	int weight = 0;

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
		data[i].setData(file);
	}

	while (file >> from >> to >> weight)
	{
		if (from == 0)
		{
			break;
		}
		C[from][to] = weight;
	}
}
//-----------------------------------------------------------------------------
//insert an edge b/w 2 given nodes
void GraphM::insertEdge(int from, int to, int weight)
{
	if (from > size || to > size)
	{
		return;
	}
	else if (from != 0 && to != 0)
	{
		C[from][to] = weight;
	}
}
//-----------------------------------------------------------------------------
//remove an edge b/w 2 given nodes
void GraphM::removeEdge(int from, int to)
{
	C[from][to] = INT_MAX;
}
//-----------------------------------------------------------------------------
//find the shortest path between every node to every other node in the
//graph, i.e., TableType T is updated with shortest path information (Dijkstra)
void GraphM::findShortestPath()
{
	int sshort = 0;
		
	for (int from = 1; from <= size; from++) 
	{
		// Distance of source vertex from itself is always 0
		T[from][from].dist = 0;
		// Find shortest path for all vertices
		for (int j = 1; j <= size; j++) 
		{
			int curMin = INT_MAX;
			for (int min = 1; min <= size; min++) //find shortest
			{ 
				//Pick the minimum distance vertex from the set of vertices not
				// yet processed.
				if (T[from][min].dist < curMin && !(T[from][min].visited)) 
				{
					curMin = T[from][min].dist;
					sshort = min;
				}
			}
			//mark picked vertex as processed 
			T[from][sshort].visited = true;

			//Update dist value of the adjacent vertices of the picked vertex.
			for (int i = 1; i <= size; i++) {
				//if not visited and not max vert
				if (!T[from][i].visited && C[sshort][i] != INT_MAX &&
					(T[from][i].dist > (T[from][sshort].dist + C[sshort][i])))
				{
					//add to dist, update shortest path
					T[from][i].dist = T[from][sshort].dist + C[sshort][i];
					T[from][i].path = sshort;
				}
			}
		}
	}
}
//-----------------------------------------------------------------------------
//uses couts to demonstrate that the algorithm works properly. display enitre graph 
void GraphM::displayAll()
{
	if (size > 0) 
	{
		cout << "Description      From node   To node    Dijkstra's   Path\n";
		//2 for loops to print number, path and distance
		for (int i = 1; i <= size; i++)
		{
			cout << data[i - 1] << endl;
			for (int j = 1; j <= size; j++)
			{
				if (T[i][j].dist != 0) 
				{
					cout << setw(23) << i << setw(9) << j; 
					//print if valid, call helper to display path
					if (T[i][j].dist == INT_MAX)
					{
						cout << setw(13) << "----" << endl;
					}
					else 
					{
						cout << setw(13) << T[i][j].dist << setw(8);
						getPathToDisplayAll(i, j);
						cout << endl;
					}
				}
			}
		}
		cout << endl << endl; 
	}
}
//-----------------------------------------------------------------------------
//helper for display all func (gives path)
void GraphM::getPathToDisplayAll(int from, int to)								
{
	if (T[from][to].dist != INT_MAX)
	{
		int path = to; 
		getPathToDisplayAll(from, T[from][to].path); 
		cout << path << " ";   
	}
}
//-----------------------------------------------------------------------------
//uses couts to display the shortest distance with path info between the 
//fromNode to toNode.
void GraphM::display(int from, int to)											
{
	//destination and origin validity
	if ((from > size || from < 0) || (to > size || to < 0))
	{
		cout << setw(7) << from << setw(7) << to;
		cout << setw(12) << "---" << endl;
		return;
	}
	cout << setw(7) << from << setw(7) << to;   
	//if able, get path to display
	if (T[from][to].dist != INT_MAX) 
	{   
		cout << setw(12) << T[from][to].dist << setw(12);
		getPathToDisplayAll(from, to); 
		cout << endl;
		getDataToDisplay(from, to); 
	}
	else
	{
		cout << setw(12) << "---" << endl;
		
	}
	cout << endl;
	

}
//-----------------------------------------------------------------------------	
//helper for display func (gives data)
void GraphM::getDataToDisplay(int from, int to)
{
	if (T[from][to].dist != INT_MAX)
	{
		int path = to;
		getDataToDisplay(from, T[from][to].path); 
		cout << data[path] << endl << endl;
	}
}
