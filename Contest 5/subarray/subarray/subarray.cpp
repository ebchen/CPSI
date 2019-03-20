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


int main()
{
	int n;
	int k;
	cin >> n;
	cin >> k;

	vector <long long> cumulative;
	long long a;
	cin >> a;
	cumulative.push_back(a);

	for (int i = 1; i < n; i++)
	{
		cin >> a;
		cumulative.push_back(cumulative[i - 1] + a);
	}

	long long minDiff = UINT64_MAX;
	long long largestSum = 0;
	bool found = false;
	bool foundMin = false;

	
	/*for (int i = n - k; i > k - 1; i--)
	{
		int iSum = cumulative[i + k - 1] - cumulative[i-1];
		for (int j = 0; j < n - k - k + 1; j++)
		{
			int jSum;
			if (j == 0) jSum = cumulative[j + k - 1];
			else jSum = cumulative[j + k - 1] - cumulative[j - 1];

			if (!foundMin)
			{
				minDiff = abs(jSum - iSum);
				foundMin = true;
			}
			

			if (abs(iSum - jSum) < minDiff)
			{
				minDiff = abs(iSum - jSum);
				largestSum = jSum + iSum;
		
			}
			else if (abs(iSum - jSum) == minDiff)
			{
				if (iSum + jSum > largestSum) largestSum = iSum + jSum;
			}
		}
	}
	*/
	

	
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	
	for (int i = 0; i <= n - 2 * k; i++)
	{
		long long sum1;
		if (i == 0) sum1 = cumulative[i + k - 1];
		else sum1 = cumulative[i + k - 1] - cumulative[i - 1];

		long long sum2 = cumulative[i + 2 * k - 1] - cumulative[i + k - 1];
		
		
		if (!foundMin)
		{
			minDiff = abs(sum1 - sum2);
			foundMin = true;
		}
		
		if (abs(sum1 - sum2) < minDiff)
		{
			minDiff = abs(sum1 - sum2);
			largestSum = sum1 + sum2;

		}
		if (!found)
		{
			largestSum = sum1 + sum2;
			found = true;
		}
		else if (abs(sum1 - sum2) == minDiff)
		{
			if ((sum1 + sum2) > largestSum) largestSum = sum1 + sum2;
		}

	}
	

	cout << largestSum << endl;
	return 0;
}

/*
6 2
3 6 7 9 6 6

6 3
1 2 3 4 5 6

9 1
1 1 6 5 8 7 11 10 9

*/