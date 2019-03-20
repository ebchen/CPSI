

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
	int R;
	int C;
	vector <string> zoo;
	vector <pair <int,int>> out;
	void output()
	{
		cin >> R;
		cin >> C;

		for (int i = 0; i < R; i++)
		{
			string line;
			cin >> line;

			for (int j = 0; j < C; j++)
			{
				if (line[j] == 'z')
				{
					pair<int, int> coords = { i + 1, j + 1 };
					out.push_back(coords);
				}
			}
		}

		for (int i = 0; i < out.size(); i++)
		{
			cout << out[i].first << " " << out[i].second << endl;
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

3 4
..z.
z.zz
....

*/

