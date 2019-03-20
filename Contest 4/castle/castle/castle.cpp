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

class djset
{
public:
	vector<int> par;

	djset(int n)
	{
		par.resize(n);
		for (int i = 0; i < n; i++) par[i] = i;

	}

	int find(int id)
	{
		if (par[id] == id) return id;
		return par[id] = find(par[id]);
	}

	bool union1 (int a, int b)
	{
		int parA = find(a);
		int parB = find(b);
		if (parA == parB) return false;
		par[parB] = parA; 
		return true;
	}
};
class Solution
{
public:
	int towers;
	int bridges;
	vector<vector<pair<int, pair<int, int>>>> adj;
	vector < pair<int, pair<int, int>>> graph;
	void output()
	{
		cin >> towers;
		cin >> bridges;

		adj.resize(towers);
		
		for (int i = 0; i < bridges; i++)
		{
			int start, end, weight;
			cin >> start >> end >> weight;
			pair <int, int> se = { start -1  , end -1};;
			pair <int, pair <int, int>> b = { weight, se };
			pair <int, int> se2 = { end - 1, start - 1};;
			pair <int, pair <int, int>> b2 = { weight, se2 };
			adj[start - 1].push_back(b);
			adj[end - 1].push_back(b2);
			graph.push_back(b);
		}

		//cout << prims() << endl;
		cout << kruskals() << endl;
	}

	long long kruskals()
	{
		sort(graph.begin(), graph.end());
		djset dj(towers);
		int numE = 0;
		long long res = 0;

		int i = 0;
		while (numE < towers - 1)
		{
			if (i == graph.size()) return -1; //checks to see if all edges have been through and mST is incomplete

			// get the next edge, skip ones that form cycles.
			pair<int,pair<int,int>> cur = graph[i];
			i++;
			bool flag = dj.union1(cur.second.first, cur.second.second);
			if (!flag) continue; // if false, means they already in same set

			//Add in weight, mark new vertex.
			res += cur.first;
			numE++;
		}
		return res;
	}
	long long prims()
	{
		priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>> > >pq;
		vector<bool> used;
		int count = 0;
		long long curr = 0;

		used.resize(towers);
		used[0] = true;

		for (int i = 0; i < adj[0].size(); i++)
		{
			pq.push(adj[0][i]);
		}

		while (count < towers - 1)
		{
			pair<int, pair<int, int>> e = pq.top(); pq.pop();
			if (used[e.second.first] && used[e.second.second]) continue;
			long long  newVertex;
			if (used[e.second.first]) newVertex = e.second.second;
			else newVertex = e.second.first;
			used[newVertex] = true;
			count++;
			curr += e.first;
			for (int i = 0; i < adj[e.second.second].size(); i++)
			{
				pq.push(adj[e.second.second][i]);
			}

		}
		return curr;
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
1 2 5
2 3 7
1 3 4

4 5
1 2 6
2 3 8
3 4 2
1 4 5
2 4 7
*/