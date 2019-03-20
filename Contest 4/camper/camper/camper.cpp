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
	int numLevels;
	long long maxCampers;

	vector<long long> interestTA;
	vector<long long> interestStudent;

	void output()
	{
		cin >> numLevels;
		cin >> maxCampers;

		for (int i = 0; i < numLevels; i++)
		{
			long long x;
			cin >> x;
			interestTA.push_back(maxCampers * x);
		}
		for (int i = 0; i < numLevels; i++)
		{
			long long x;
			cin >> x;
			
			if (interestTA[i] >= x) cout << 1;
			else cout << 0;
		}

		cout << endl;
	}
	
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}