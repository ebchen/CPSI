
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
	int n, m, k;
	vector<vector<char>> board;
	vector<vector<int>> points;
	vector<vector<bool>> visited;
	Solution()
	{
		cin >> n;
		cin >> m;
		cin >> k;

		for (int i = 0; i < n; i++)
		{
			vector<char> row;
			for (int j = 0; j < m; j++)
			{
				char dial;
				cin >> dial;
				row.push_back(dial);
			}
			board.push_back(row);
		}

		for (int i = 0; i < n; i++)
		{
			vector<int> row;
			for (int j = 0; j < m; j++)
			{
				int pts;
				cin >> pts;
				row.push_back(pts);
			}
			points.push_back(row);
		}

		for (int i = 0; i < n; i++)
		{
			vector <bool> row;
			for (int j = 0; j < m; j++)
			{
				row.push_back(false);
			}
			visited.push_back(row);
		}
	}

	int dfs(int row, int col, char dial, int changes)
	{
		int state; /* 1 = /   2= |     3= \   */
		if (dial == '#') return 0;
		else if (dial == '/') state = 1;
		else if (dial == '\\') state = 3;
		else state = 2;

		int totalScore = points[row][col];

		int bestScore = 0;
		//visited[row][col] = true;
		
		int nextX;
		int nextY;

		int score;
		if (row == n-1) return 0;

		if (state == 1)
		{
			nextX = row + 1;
			nextY = col - 1;
			score = dfs(nextX, nextY, board[nextX][nextY], changes);
			if (score > bestScore) bestScore = score;

			if (changes != 0)
			{
				nextX = row + 1;
				nextY = col;
				changes--;
				score = dfs(nextX, nextY, board[nextX][nextY], changes);
				if (score > bestScore) bestScore = score;

				
				nextX = row + 1;
				if (col != m - 1) nextY = col + 1;
				changes--;
				score = dfs(nextX, nextY, board[nextX][nextY], changes);
				if (score > bestScore) bestScore = score;
			}
		}
		
		if (state == 2)
		{
			nextX = row + 1;
			nextY = col;
			score = dfs(nextX, nextY, board[nextX][nextY], changes);
			if (score > bestScore) bestScore = score;

			if (changes != 0)
			{
				nextX = row + 1;
				if (col != m - 1) nextY = col+1;
				changes--;
				score = dfs(nextX, nextY, board[nextX][nextY], changes);
				if (score > bestScore) bestScore = score;

				nextX = row + 1;
				if (col != 0) nextY = col - 1;
				changes--;
				score = dfs(nextX, nextY, board[nextX][nextY], changes);
				if (score > bestScore) bestScore = score;
			}
		}

		if (state == 3)
		{
			nextX = row + 1;
			nextY = col + 1;
			score = dfs(nextX, nextY, board[nextX][nextY], changes);
			if (score > bestScore) bestScore = score;

			if (changes != 0)
			{
				nextX = row + 1;
				nextY = col;
				changes--;
				score = dfs(nextX, nextY, board[nextX][nextY], changes);
				if (score > bestScore) bestScore = score;

				nextX = row + 1;
				if (col != 0) nextY = col - 1;
				changes--;
				score = dfs(nextX, nextY, board[nextX][nextY], changes);
				if (score > bestScore) bestScore = score;
			}
		}
		
		
		return bestScore + totalScore;
	}

	void output()
	{
		int most = 0;
		
			for (int j = 0; j < m; j++)
			{
				int score = dfs(0, j, board[0][j], k);
				if (score > most) most = score;
			}
		

		cout << most;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*

4 4 2
\//|
#\||
\#\/
|//\
3 6 4 3
0 4 5 3
9 0 7 3
4 7 4 6
*/


/*

Use dynamic programming

state has row, col, and knobTurns

example
\  |  /
  15
dp[row][col][k] =	grid[row][col] + dp[row-1][col-1][k-1],
					grid[row][col] + dp[row-1][col][k],
					grid[row][col] + dp[row-1][col+1][k].
*/