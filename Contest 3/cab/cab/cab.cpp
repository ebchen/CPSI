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
#include <queue>
#include <deque>
using namespace std;

class Solution
{
public:
	char last;
	int n;
	int lastInd;
	vector <string> words;
	vector<vector<char>> adjacency;
	vector<int> indegrees;
	string order = "";
	char alpha[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	void output()
	{
		cin >> last;
		cin >> n;
		lastInd = last - 97;

		for (int i = 0; i < n; i++)
		{
			string x;
			cin >> x;
			words.push_back(x);
		}
		for (int i = 0; i < lastInd + 1; i++)
		{
			vector<char> row;
			adjacency.push_back(row);

			indegrees.push_back(0);
		}

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				string word1 = words[i];
				string word2 = words[j];
			
				if (word1.length() > word2.length() && word1.substr(0, word2.length()) == word2)
				{
					cout << 1 << endl;
					return;
				}
				for (int k = 0; k < word1.length() &&  k < word2.length(); k++)
				{

					if (word1[k] != word2[k])
					{
						int index = word1[k] - 97;
						bool found = false;
						for (int l = 0; l < adjacency[index].size(); l++)
						{
							if (word2[k] == adjacency[index][l])
							{
								found = true;
								break;
							}
						}
						if (found == false)
						{
							char letter = word2[k];
							adjacency[index].push_back(letter);
							indegrees[word2[k] - 97]++;
						}
						break;
					}
				}
			}
		}
		int w = topoSort();
		if (w == -1)
			cout << order << endl;
		else
			cout << w << endl;
	}

	/*
	int topologicalSort() //Brads
	{
		queue<int> q;

		for (int i = 0; i <= last-97; i++)
			if (indegrees[i] == 0) q.push(i);
		
		bool mult = false;

		int it = 0;
		while (!q.empty())
		{
			if (q.size() > 1) mult = true; //multiple options
			auto cur = q.front(); q.pop();
			order += cur;
			for (auto e : adjacency[cur])
				if (--indegrees[e-97] == 0) q.push(e);
		}

		if (it != last + 1) return 1;

		if (mult) return 0; //multiple options - incomplete
		return -1;
	}
	*/
	

	int topoSort()
	{
		deque<int> zeroes;

		for (int i = 0; i < indegrees.size(); i++)
		{
			if (indegrees[i] == 0)
				zeroes.push_back(i);
		}

		while (!zeroes.empty())
		{
			if (zeroes.size() > 1) return 0;
			int x = zeroes.front();
			zeroes.pop_front();
			order += alpha[x];
			for (int neighbor : adjacency[x])
			{
				indegrees[neighbor - 97]--;
				if (indegrees[neighbor - 97] == 0)
				{
					zeroes.push_back(neighbor - 97);
				}
			}
		}
		if (order.length() == indegrees.size()) return -1;
		return 1;

	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}
/*

c a b
c d a
c c c
badca

implementing:
	for each pair of words next to each other, find the first discrepancy

top sort
construct path
use dueling philosophers solution

*/