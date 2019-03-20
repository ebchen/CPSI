
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <deque>


using namespace std;

class Solution
{
public:
	int numberOfNodes;
	int numberOfEdges;
	int numberOfCenters;
	vector<int> costs;
	vector<vector<int>> adjacency;
	vector <int> nodeCosts;
	
	
	void bfs(int start)
	{
		int cprice = costs[start];
		vector<int>::iterator it;
		bool *visited = new bool[numberOfNodes];
		for (int i = 0; i < numberOfNodes; i++)
			visited[i] = false;
		int depth = 0;
		deque<int> dq;
		visited[start] = true;
		dq.push_back(start);

		
		while (!dq.empty())
		{
			depth++;
			start = dq.front();
			
			dq.pop_front();

			for (it = adjacency[start].begin(); it != adjacency[start].end(); it++)
			{
				if (!visited[*it])
				{
					int price = depth * cprice;
					if (nodeCosts[start] > price) nodeCosts[start] = price;
					visited[*it] = true;
					dq.push_back(*it);
				}
			}
		}
	}
	void output()
	{
		cin >> numberOfNodes;
		cin >> numberOfEdges;
		cin >> numberOfCenters;

		costs.push_back(0);
		for (int i = 0; i < numberOfCenters; i++)
		{
			int cost;
			cin >> cost;
			costs.push_back(cost);
		}

		adjacency.resize(numberOfNodes+1);

		for (int i = 0; i < numberOfEdges; i++)
		{
			int a, b;
			cin >> a;
			cin >> b;
			adjacency[a].push_back(b);
			adjacency[b].push_back(a);
		}

		nodeCosts.resize(numberOfNodes+1);


		fill(nodeCosts.begin(), nodeCosts.end(), INT_MAX);
		for (int i = 1; i <= numberOfCenters; i++)
		{
			nodeCosts[i] = 0;
		}


		for (int i = 1; i <= numberOfCenters; i++)
		{
			bfs(i);
		}
		int sum = 0;
		for (int i = numberOfCenters+1; i <= numberOfNodes; i++)
		{
			sum += nodeCosts[i];
		}
		

		cout << sum << endl;




		
	}

};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*
Solution:
BFS
set all homes to infinity first.
loop through all the distribution centers and run bfs for all
save the minimum cost
for every node, whats the cost to deliver from each delivery center
*/
/*
13 20 3
65 24 20
2 5
5 13
13 8
8 3
3 11
11 9
9 1
1 12
12 7
7 6
6 2
13 11
13 4
4 9
13 10
5 10
6 10
7 10
1 10
7 4

*/