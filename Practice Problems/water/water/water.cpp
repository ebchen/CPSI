
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
	int r;
	int c;
	vector<string> map;
	vector<vector<bool>> visited;

	void dfs(int x, int y )
	{
		//int totalArea = 1;
		visited[x][y] = true;

		int dX[] = { -1,1,0,0 };
		int dY[] = { 0, 0,1, -1 };
		
		for (int i = 0; i < 4; i++)
		{
			int xChange = dX[i];
			int yChange = dY[i];

			if (xChange == -1 && x == 0) continue;
			if (xChange == 1 && x == r - 1) continue;
			if (yChange == -1 && y == 0) continue;
			if (yChange == 1 && y == c - 1) continue;

			if (visited[x + xChange][y + yChange] == false && map[x + xChange][y + yChange] == 'w')
			{
				dfs(x + xChange, y + yChange);
			}
		}

		return;
		
	}

	void output()
	{
		cin >> r;
		cin >> c;

		for (int i = 0; i < r; i++)
		{
			string row;
			cin >> row;

			map.push_back(row);
		}
		
		for (int i = 0; i < r; i++)
		{
			vector< bool> row;
			for (int j = 0; j < c; j++)
			{
				row.push_back(false);
			}
			visited.push_back(row);
		}

		int bodyCount = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (map[i][j] == 'w' && visited[i][j] == false)
				{
					bodyCount++;
					dfs(i, j);
					
				}
			}
		}

		cout << bodyCount << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*
5 6
waaaww
wawawc
bbbbwc
wwwwww
dddddd
*/

/*
2 8
wxwxwxwx
xwxwxwxw
*/




