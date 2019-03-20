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
	int campers;
	int TAs;
	vector<int> times;

	bool check( int t) // to see if time t is valid
	{
		int left = 0;
		int count = 1;
		for (int right = 0; right < campers; right++)
		{
			if (times[right] - times[left] > t)
			{
				left = right;
				count++;
			}
		}

		if (count > TAs) return 0;
		else return 1;
	}

	int binarySearch()
	{
		int low = 0;
		int high = times[times.size() - 1] - times[0];
		int mid = (low + high) / 2;
		//int least = INT_MAX/2;
		while (low < high)
		{
			if (check(mid))
			{
				high = mid;
				mid = (low + high) / 2;
			}
			else
			{
				low = mid + 1;
				mid = (low + high) / 2;
			}
		}

		return low;

	}
	void output()
	{
		cin >> campers;
		cin >> TAs;

		for (int i = 0; i < campers; i++)
		{
			int x;
			cin >> x;
			times.push_back(x);
		};

		sort(times.begin(), times.end());

		cout << binarySearch() << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();

	return 0;
}/*
 use greedy algorithm to assume the time and see if it works. Keep trying
 */