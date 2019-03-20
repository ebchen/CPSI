

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
	int m;
	int k;

	void output()
	{
		cin >> n;
		cin >> m;

		vector<vector<int>> bottles;

		for (int i = 0; i <= n+1; i++)
		{
			vector<int> row;
			row.resize(m+2);
			fill(row.begin(), row.end(), 0);
			bottles.push_back(row);
		}
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			int x; // in direction n
			int y; // in direction m
			long long flips;

			cin >> x;
			cin >> y;
			cin >> flips;

			// Dx and Dy Arrays
			//	int[] dX = {-1,0,0,0,1}				each represent one of the five flipped squares
			//	int[] dY = {0,-1,0,1,0}
			//

			// up right down left
			if (flips % 2 == 1)    // bottles[x][y] = 1 - bottles[x][y]
			{
				if (bottles[x][y] == true) bottles[x][y] = false;
				else bottles[x][y] = true;

				if (bottles[x - 1][y] == true) bottles[x - 1][y] = false;
				else bottles[x - 1][y] = true;

				if (bottles[x + 1][y] == true) bottles[x + 1][y] = false;
				else bottles[x + 1][y] = true;

				if (bottles[x][y-1] == true) bottles[x][y-1] = false;
				else bottles[x][y-1] = true;

				if (bottles[x][y+1] == true) bottles[x][y+1] = false;
				else bottles[x][y+1] = true;
			}
			
		}

		for (int i = 1; i < bottles.size() - 1; i++)
		{
			for (int j = 1; j < bottles[i].size() - 1; j++)
			{
				cout << bottles[i][j];
			}
			cout << endl;
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
4 4
1
2 2 3
*/