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
	int x;
	int y;
	int start;
	int segments;
public:
	void output()
	{
		x = 0;
		y = 0;
		cin >> start;
		cin >> segments;

		int counter = 0;

		for (int i = 0; i < segments; i++)
		{
			if (i % 4 == 0)
			{
				x += (start + i);
			}

			else if (i % 4 == 1)
			{
				y -= (start + i);
			}

			else if (i % 4 == 2)
			{
				x -= (start + i);
			}

			else
			{
				y += (start + i);
			}
		}

		cout << x << " " << y << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}