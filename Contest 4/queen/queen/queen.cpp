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
	int r;
	int c;
	vector<string> board;
	pair<int, int> queen;
	vector<vector<bool>> visited;
	int dX [8] = { -1, -1,0, 1, 1, 1, 0, -1 };
	int dY [8] = { 0, 1, 1, 1, 0 , -1 , -1, -1 };
	
	int bfs()
	{
		deque<pair<int,int>>dq;

		dq.push_back(queen);
		visited[queen.first][queen.second] = true;

		if (queen.first == 1 || queen.first == r || queen.second == 1 || queen.second == c) return 0;
	
		while (!dq.empty())
		{
			pair<int,int> curr = dq.front(); dq.pop_front(); 

			for (int i = 0; i < 8; ++i)
			{
				int newX = curr.first + dX[i];
				int newY = curr.first + dX[i];
			}
		}
	
	}

	void output()
	{
		ios::sync_with_stdio(0); cin.tie(0);
		cin >> r;
		cin >> c;

		// padding the border with Xs
		string pad = "";
		for (int i = 0; i < c; i++)
		{
			pad += "X";
		}
		board.push_back(pad);
		for (int i = 0; i < r; i++)
		{
			
			string x;
			cin >> x;
			x = "X" + x + "X";
			board.push_back(x);
		}
		board.push_back(pad);

		//finding the queens position
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (board[i][j] == 'Q')
				{
					queen.first = i;
					queen.second = j;
				}
			}
		}
		
		//intializing visited matrix.
		visited.resize(r);
		for (int i = 0; i < r; i++)
		{
			visited[i].resize(r);
		}



		
	}
};

int main()
{
	return 0;
}


/*
case Queen is on border

do bfs, and store distance in distance arrays
use a queue and put all the cells in.
Use dX dY array to check all 8 directions

for (int dist = 1;;dist++)
{
	nX = x + dX[i] *dist;
	nY = y + dY[i] + dist;
	if (!inbounds(nX,nY) || grid[nX][nY[ == 'X'){
		break;
	}
}

*/