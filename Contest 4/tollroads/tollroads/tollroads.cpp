#include <vector>
#include <fstream>
#include <math.h>
#include <climits>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <deque>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <random>
#include <cstring>
#include <complex>
#include <cassert>

using namespace std;

class Solution
{
public:
	int nodes;
	int roads;
	int max;
	int roadTimes[1100][1100];
	int roadCosts[1100][1100];

	void output()
	{
		cin >> nodes;
		cin >> roads;
		cin >> max;

		for (int i = 0; i < roads; i++)
		{
			int u, v, c, t;
			cin >> u >> v >> c >> t;
			roadTimes[u][v] = t;
			roadTimes[v][u] = t;
			roadCosts[u][v] = c;
			roadCosts[v][u] = c;
		}

		cout << dijkstra() << endl;
	}

	int dijkstra()
	{
		int cost = 0;
		vector <int> visited;
		visited.resize(nodes+1);

		vector<int> weights;
		weights.resize(nodes+1);

		int filled = 0;
		fill(weights.begin(), weights.end(), INT_MAX/2);
		weights[1] = 0;

		while (filled != nodes) {
			int leastWeight = INT_MAX/2;
			int leastWeightIndex = -1;
			for (int i = 0; i < nodes; i++)
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
			cost+= roadCosts[]

			for (int j = 0; j < nodes; j++)
			{
				weights[j] = min(weights[j], weights[leastWeightIndex] + roadTimes[leastWeightIndex][j]);
			}

		}
		return weights[nodes - 1];
	}
};

int main()
{
	return 0;
}

/*
node splitting
then use dijkstras


*/