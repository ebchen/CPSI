

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
	string input;

	void output()
	{
		cin >> n;
		cin >> input;

		int zeroCount = 0;
		for (int i = 0; i < n; i++)
		{
			if (input[i] == '0') zeroCount++;
		}

		int minimum = zeroCount;

		for (int x = 0; x < n-1; x++)
		{
			int left = x;
			int right = x + 1;
			int newSize = max(x + 1, n-(x+1));
			int rangeToBeConsidered = n - newSize ;
			int zeroesDeleted = 0;

			for (int i = 0; i <= rangeToBeConsidered; i++) //off by one?
			{
				bool val1;
				bool val2;
				if (input[left] == '0')
				{
					val1 = false;
				}
				else
				{
					val1 = true;
				}

				if (input[right] == '0')
				{
					val2 = false;
				}
				else
				{
					val2 = true;
				}
				if (!(val1 && val2)) zeroesDeleted++;
				if (left == 0)	break;
				if (right == n-1) break;
				left--;
				right++;
			}
			if (zeroCount - zeroesDeleted < minimum) minimum = zeroCount - zeroesDeleted;
			//cout << "when x is " << x << ", zeroesDeleted is: " << zeroesDeleted << endl;
		}

		cout << minimum << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*



*/