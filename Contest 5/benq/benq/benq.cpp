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

};

int main()
{

	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	vector<int> costs;
	vector<long long > resources;

	long long cost = 0;


	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		
		costs.push_back(x);
	}

	long long a;
	cin >> a;
	resources.push_back(a);
	for (int i = 1; i < n; i++)
	{
		long long x;
		cin >> x;
		resources.push_back(x + resources[i - 1]);
	}


	int start = 0;
	int minPrice = costs[0];
	for (int i = 1; i < n; i++)
	{
		if (costs[i] < minPrice)
		{
			if (start == 0)
			{
				cost += resources[i - 1] * minPrice;
			}
			else cost += ((resources[i-1] - resources[start - 1]) * minPrice);
			start = i;
			minPrice = costs[i];
		}

	}
	if (start == 0)
	{
		cost += resources[n - 1] * minPrice;
	}
	else cost += ((resources[n - 1] - resources[start - 1]) * minPrice);

	cout << cost << endl;
	return 0;
}
/*




*/