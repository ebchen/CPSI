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
	int ratingChange;
	int numChanges;
	int numIgnore;
	vector <int> deltas;
public:
	void output()
	{
		ratingChange = 0;
		
		cin >> numChanges;
		cin >> numIgnore;
		if (numChanges <= 0)
		{
			cout << 0 << endl;
			return;
		}
		for (int i = 0; i < numChanges; i++)
		{
			int d;
			cin >> d;
			deltas.push_back(d);
		}

		sort(deltas.begin(), deltas.end());

		for (int i = 0; i < numIgnore; i++)
		{
			if (deltas[i] < 0)
			{
				ratingChange += deltas[i];
			}

			if (deltas[i] >= 0) break;
			
		}
		ratingChange = ratingChange * -1;
		cout << ratingChange << endl;

	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}