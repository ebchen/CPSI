/*
ID: eric.ch2
PROG: PROGRAM_NAME
LANG: C++11
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;


class Solution
{
public:
	int numberOfVotes;
	map <string, int> votes;
	void output()
	{
		cin >> numberOfVotes;

		for (int i = 0; i < numberOfVotes; i++)
		{
			string vote;
			cin >> vote;

			map<string,int>::iterator it = votes.find(vote);
			if (it == votes.end())
			{
				votes.insert(pair<string, int>(vote, 1));
			}
			else
			{
				it->second++;
			}

			
		}

		vector<string>winners;
		int most = 0;
		
		for (map<string, int>::iterator it = votes.begin(); it != votes.end(); it++)
		{
			if (it->second > most)
			{
			
				most = it->second;
				winners.clear();
				winners.push_back(it->first);
			}
			else if (it->second == most)
			{
				winners.push_back(it->first);
			}
		}

		sort(winners.begin(),winners.end());
		for (int i = 0; i < winners.size(); i++)
		{
			cout << winners[i] << endl;
		}
	}

};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}