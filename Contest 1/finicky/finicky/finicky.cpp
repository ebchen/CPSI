
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
	int happiness;
	int end;
	int curr;
	int numberOfItems;
	int cost;
	vector<vector<int>> items;
public:

	vector<int> findBestInRange()
	{
		bool found = false;
		vector<int>best = {};
		for (int i = 0; i < numberOfItems; i++)
		{
			if ((items[i][0] > curr) && (items[i][0] <= curr + happiness))
			{
				if (!found)
				{
					best.push_back(items[i][0]);
					best.push_back(items[i][1]);
					best.push_back(items[i][2]);
					found = true;
				}
				else
				{
					if (items[i][2] > (best[2] + (items[i][0] - best[0])))
					{
						best[0] = items[i][0];
						best[1] = items[i][1];
						best[2] = items[i][2];
					}
					else if (items[i][2] == (best[2] + (items[i][0] - best[0])))
					{
						if (items[i][1] < best[1])
						{
							best[0] = items[i][0];
							best[1] = items[i][1];
							best[2] = items[i][2];
						}
					}
				}
			}
		}
		return best;
	}

	void output()
	{
		curr = 0;
		int numberOfItems;
		cost = 0;
		cin >> happiness;
		cin >> end;
		cin >> numberOfItems;

		
		for (int i = 0; i < numberOfItems; i++)
		{
			int x;
			cin >> x;
			int cost;
			cin >> cost;
			int value;
			cin >> value;

			vector<int> item = { x, cost, value };
			items.push_back(item);
		}

		bool e = false;
		while (!e)
		{
			if (curr + happiness >= end)
			{
				cout << cost << endl;
				break;
			}

			vector<int> best = findBestInRange();
			if (best.size() == 0)
			{
				cout << -1 << endl;
				return;
			}
			int oldCurr = curr;
			curr = best[0];
			cost += best[1];
			happiness = happiness + best[2] - (curr - oldCurr);
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

dynamic programming
states: when arriving at a toy stop

f(x,h) min cost from this point forward to make it to the end

return min(buying, not buying);

memoization:
array memo
memo[x][h]

return memo[x][h] = recursive function

*/