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

class Cell
{
public:
	int turns;
	int direct;
	int x;
	int y;

	Cell(int t, int d, int x1, int y1)
	{
		turns = t;
		direct = d;
		x = x1;
		y = y1;
	}

	/*
	bool operator< (const Cell& o) const
	{
		if (turns <= o.turns) return true;
		else return false;
	}
	*/
	
	bool operator> (const Cell& o) const
	{
		if (turns <= o.turns) return false;
		else return true;
	}
	
};
class Solution
{
public:
	int R;
	int C;
	int direction; //0 is north, 1 is east, 2 is south, 3 is west
	vector<string> board;
	pair<int, int> spencer;
	vector<vector<bool>> visited;
	int dX[4] = { -1, 0, 1, 0 }; // N, E, S, W
	int dY[4] = { 0, 1,  0 , -1 };

	int turn(int dir, int delta)
	{
		if (dir == 0) // pointing north
		{
			if (delta == 0) //going north
			{
				return 0;
			}
			else if (delta == 1) // going east
			{
				return 1;
			}
			else if (delta == 2) // going south
			{
				return 2;
			}
			else if (delta == 3) // going west
			{
				return 1;
			}
		}
		else if (dir == 1) // pointing east
		{
			if (delta == 0) //going north
			{
				return 1;
			}
			else if (delta == 1) // going east
			{
				return 0;
			}
			else if (delta == 2) // going south
			{
				return 1;
			}
			else if (delta == 3) // going west
			{
				return 2;
			}
		}
		else if (dir == 2) // pointing south
		{
			if (delta == 0) //going north
			{
				return 2;
			}
			else if (delta == 1) // going east
			{
				return 1;
			}
			else if (delta == 2) // going south
			{
				return 0;
			}
			else if (delta == 3) // going west
			{
				return 1;
			}
		}
		else // going west
		{
			if (delta == 0) //going north
			{
				return 1;
			}
			else if (delta == 1) // going east
			{
				return 2;
			}
			else if (delta == 2) // going south
			{
				return 1;
			}
			else if (delta == 3) // going west
			{
				return 0;
			}
		}

		return 0;
	}

	int bfs()
	{
		deque<vector<int>>dq;
		priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
		if (spencer.first == 1 || spencer.first == R || spencer.second == 1 || spencer.second == C) return 0;
		/*
		vector<int>cell;
		cell.push_back(0);
		cell.push_back(direction);
		cell.push_back(spencer.first);
		cell.push_back (spencer.second);

		dq.push_back(cell);
		*/

		Cell cell(0, direction, spencer.first, spencer.second);
		pq.push(cell);
		visited[spencer.first][spencer.second] = true;

		while (!pq.empty())
		{
			Cell curr = pq.top();
			pq.pop();
			visited[curr.x][curr.y] = true;
			if (curr.x == 1 || curr.x == R || curr.y == 1 || curr.y == C) return curr.turns;

			
			for (int i = 0; i < 4; ++i)
			{
				int newX = curr.x + dX[i];
				int newY = curr.y + dY[i];
				
				if (board[newX][newY] == '_' && !visited[newX][newY])
				{
					Cell coords(curr.turns += turn(curr.direct, i), i, newX, newY );
					pq.push(coords);
				}
			}
		}
		return -1;

	}

	void output()
	{
		ios::sync_with_stdio(0); cin.tie(0);
		cin >> R;
		cin >> C;

		// padding the border with Xs
		string pad = "";
		for (int i = 0; i < C; i++)
		{
			pad += "X";
		}
		board.push_back(pad);
		for (int i = 0; i < R; i++)
		{

			string x;
			cin >> x;
			x = "X" + x + "X";
			board.push_back(x);
		}
		board.push_back(pad);

		//finding the spencers position
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (board[i][j] == 'N'|| board[i][j] == 'W' || board[i][j] == 'E' || board[i][j] == 'S' )
				{
					spencer.first = i;
					spencer.second = j;
					if (board[i][j] == 'N') direction = 0;
					else if (board[i][j] == 'E') direction = 1;
					else if (board[i][j] == 'S') direction = 2;
					else direction = 3;
				}
			}
		}

		//intializing visited matrix.
		visited.resize(R);
		for (int i = 0; i < R; i++)
		{
			visited[i].resize(C);
		}


		cout << bfs() << endl;

	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*
5 5
XXX__
XNX_X
X_X_X
X___X
XXXXX


5 7
XXXXXXX
__XXX__
__XWX__
__XXX__
_______
*/