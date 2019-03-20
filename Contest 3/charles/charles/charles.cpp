#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

class Solution
{
public:
	vector <vector<int>> adjacency;
	int n;
	int m;
	int inf = 0x3f3f3f3f;
	long long infL = 0x3f3f3f3f3f3f3f3f;
	vector < pair<int, pair<int, int>>> edges;

	int dijkstra(vector<vector<int>>& adjacency)
	{
		vector <char> visited;
		visited.resize(adjacency.size());

		vector<int> weights;
		weights.resize(adjacency.size());

		int filled = 0;
		fill(weights.begin() , weights.end(), inf);
		weights[0] = 0;

		while (filled != adjacency.size()) {
			int leastWeight = inf;
			int leastWeightIndex = -1;
			for (int i = 0; i < adjacency.size(); i++)
			{
				if (!visited[i]) 
				{
					if (weights[i] < leastWeight)
					{
						leastWeight = weights[i];
						leastWeightIndex = i;
					}
				}
			}

			visited[leastWeightIndex] = true;
			filled++;

			for (int j = 0; j < adjacency.size(); j++)
			{
				weights[j] = min(weights[j], weights[leastWeightIndex] + adjacency[leastWeightIndex][j]);
			}

		}
		return weights[adjacency.size() - 1];
	}
	void output()
	{
		
		cin >> n;
		cin >> m;

		for (int i = 0; i < n; i++)
		{
			vector<int> row;
			row.resize(n);
			fill(row.begin(), row.end(), inf);
			adjacency.push_back(row);
		}

		for (int i = 0; i < m; i++)
		{
			int s, e, w;
			cin >> s;
			cin >> e;
			cin >> w;

			adjacency[s-1][e-1] = w;
			adjacency[e-1][s-1] = w;

			pair <int, pair<int, int>> edge;	
			edge.first = w;
			edge.second.first = s;
			edge.second.second = e;
			edges.push_back(edge);
		}

		int other = dijkstra(adjacency);
		
		for (int i = 0; i < m; i++) {
			
			pair <int, pair<int, int>> edge;
			int dif;
			cin >> dif;
			adjacency[edges[i].second.first-1][edges[i].second.second-1] += dif;
			adjacency[edges[i].second.second-1][edges[i].second.first-1] += dif;
		}

		int charles = dijkstra(adjacency);

		cout << charles - other << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();

	return 0;
}

/*
3 3
1 2 10
2 3 10
1 3 10
-5 0 15



3 3
1 2 10
2 3 10
1 3 10
5 0 0



*/

/*
when using pq use a state.
store weights



*/