

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

class Edge
{
public:
	int myU;
	int myV;
	int myW;

	Edge(int u, int v, int w)
	{
		myU = u;
		myV = v;
		myW = w;
	}

	bool operator< (const Edge& otherEdge) const
	{
		if (myW > otherEdge.myW) return false;
		else return true;
	}
};

int getMST(vector<Edge> graph)
{
	//////////////////////
	//
	// PRIM'S
	//
	//////////////////////

	// initialize stuff
	int mst = 0, numE = 0;
	vector<bool> used;
	used.resize(n); // the number of vertices
	priority_queue<Edge> pq;
	used[0] = true;

	// Add all edges incident to 0 to pq.
	for (int i = 0; i < graph.size(); i++)
	{
		pq.push(graph[i]);
	}

	// Go until you get all edges
	while (numE < n - 1)
	{
		// No MST exists.
		if (pq.size() == 0) return -1;

		// get the next edge.
		Edge e = pq.top();

		// These two are already connected.
		if (used[e.myU] && used[e.myV]) continue;

		int newV = used[e.myU] ? e.myV : e.myU;

		// Add edge to the MST.
		used[newV] = true;
		mst += e.myW;

		// Add edges incident to newV.
		for (int i = 0; i < graph.size(); i++)
		{
			pq.push(graph[i]);
		}
	}
}
int main()
{

	int n;
	int numCases;
	cin >> numCases;

	for (int i = 1; i < numCases; i++)
	{

	}
	cin >> n;

	vector<Edge> graph;

	
	}

	return 0;
}