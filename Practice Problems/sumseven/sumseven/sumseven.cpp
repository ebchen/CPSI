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
using namespace std;

class Solution
{
public:
	int n;
	vector<long long> ids;

	void output()
	{
		cin >> n;

		ids.push_back(0);
		for (int i = 0; i < n; i++)
		{
			int id;
			cin >> id;
			ids.push_back(id);
		}

		for (int i = 1; i <= n; i++)
		{
			if (i > 0)
				ids[i] += ids[i - 1];
			
		}
		int largestGroup = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				
				if ((ids[j] - ids[i - 1]) % 7 == 0)
				{
					int size = j - i + 1;
					if (size > largestGroup) largestGroup = size;
				}
			}
		}

		cout << largestGroup << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}