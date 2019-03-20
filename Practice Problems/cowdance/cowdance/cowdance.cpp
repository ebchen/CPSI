#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
	int n;
	int maxT;
	vector<int> times;
	

	void output()
	{
		//ifstream fin("cowdance.in");
		//fin >> n;
		//fin >> maxT;
		cin >> n;
		cin >> maxT;

		for (int i = 0; i < n; i++)
		{
			int t;
			//fin >> t;
			cin >> t;
			times.push_back(t);
		}

		int low = 1;
		int high = n;

		while (low < high)
		{
			// see if we need +1 plug in 2 and 3
			int mid = (low + high) / 2;

			// returns the ime it takes for the cows with mid# of spots
			int time = sim(mid);

			// ran in time, answer is at most mid.
			if (time <= maxT)
			{
				high = mid;
			}
			// answer must be bigger than mid
			else
				low = mid+1;
		}

		// answer is low.

		//ofstream fout;
		//fout.open("cowdance.out");
		//fout << low << endl;
		cout << low << endl;
	}
	 
	// simulate show with stage of size mid
	int sim(int x)
	{
		priority_queue <int, vector<int>, greater<int> > pq;
		for (int i = 0; i < x; i++)
		{
			pq.push(times[i]);
		}

		int curI = x;
		int nextT = 0;
		// keep on going until all cows down
		while (!pq.empty())
		{
			nextT = pq.top();
			pq.pop();

			if (curI < times.size())
			{
				pq.push(nextT + times[curI++]);

			}
		}
		return nextT;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}