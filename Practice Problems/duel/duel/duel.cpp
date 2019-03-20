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
#include <deque>
#include <stack>
#include <bitset>
#include <random>
#include <cstring>
#include <complex>
#include <cassert>
using namespace std;

int topSort(vector<int>&inDegree, int essays, vector<vector<int>>&adjacency)
{
	vector<bool> visited;
	visited.resize(essays);
	fill(visited.begin(), visited.end(), false);

	deque<int> zeroes;
	int count = 0;
	bool multipleZeroes = false;
	for (int i = 0; i < inDegree.size(); i++)
	{
		if (inDegree[i] == 0)
			zeroes.push_back(i);
	}
	if (zeroes.size() == 0) return 0;
	if (zeroes.size() > 1) multipleZeroes = true;

	while (!zeroes.empty())
	{
		if (zeroes.size() > 1) multipleZeroes = true;

		int x = zeroes.front();
		zeroes.pop_front();
		visited[x] = true;
		for (int neighbor : adjacency[x])
		{
			inDegree[neighbor]--;
			if (inDegree[neighbor] == 0)
			{
				zeroes.push_back(neighbor);
			}
		}

	}

	for (int i = 0; i < visited.size(); i++)
	{
		if (visited[i] == false) return 0;
		if (inDegree[i] > 0) return 0;
	}
	if (multipleZeroes) return 2;
	return 1;
}

int main()
{
	int essays;
	int relations;
	vector <vector<int>> adjacency;
	vector <int> inDegree;
	vector<int> output;
	ios::sync_with_stdio(0); cin.tie(0);

	bool terminate = false;
	do {
		adjacency.clear();
		inDegree.clear();
		cin >> essays;
		cin >> relations;


		if (essays == 0 && relations == 0)
		{
			terminate = true;
			continue;
		}

		adjacency.resize(essays);
		for (int i = 0; i < essays; i++)
		{
			adjacency[i].resize(essays);
			inDegree.push_back(0);
		}

		for (int i = 0; i < relations; i++)
		{
			int d;
			int u;
			cin >> d;
			cin >> u;

			adjacency[d - 1].push_back(u - 1);
			inDegree[u - 1]++;
		}

		output.push_back(topSort(inDegree, essays, adjacency));


	} while (terminate == false);

	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << endl;
	}

	return 0;
}