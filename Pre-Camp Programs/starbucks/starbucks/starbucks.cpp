
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
private:
	int frapCost;
	int popCost;
	int cents;
	int numPairs;
public:
	void output()
	{
		cin >> frapCost;
		cin >> popCost;
		cin >> cents;
		numPairs = 0;
		int maxFraps = cents / frapCost;
		for (int i = 0; i <= maxFraps; i++)
		{
			int frapTotal = frapCost * i;
			int remainder = cents - frapTotal;
			if (remainder % popCost == 0)
			{
				numPairs++;
			}
		}
		cout << numPairs << endl;
		return;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}