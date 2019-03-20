

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
	vector <long long> dens;
public:
	void output()
	{
		int farmSize;
		cin >> farmSize;
		int numActions;
		cin >> numActions;

		for (int i = 0; i < farmSize; i++)
		{
			long long pop;
			cin >> pop;
			dens.push_back(pop);
		}
		
		for (int i = 0; i < numActions; i++)
		{
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				long long index;
				cin >> index;
				long long newPop;
				cin >> newPop;

				dens[index - 1] *= newPop;
			}
			else
			{
				long long l1;
				long long l2;
				long long r1;
				long long r2;

				cin >> l1;
				cin >> l2;
				cin >> r1;
				cin >> r2;

				if (dens[l1 - 1] > dens[r1 - 1]) cout << 1 << endl;
				else if (dens[l1 - 1] == dens[r1 - 1]) cout << 0 << endl;
				else cout << -1 << endl;
			}
		}
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*

binary index tree

point and range queries

*/