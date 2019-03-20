

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

class Bench
{
public:
	int ducksPresent;
	int expectedFood;
	int number;

	Bench(int d, int e, int n)
	{
		ducksPresent = d;
		expectedFood = e;
		number = n;
	}

	bool operator< (const Bench& otherBench) const
	{
		if (expectedFood > otherBench.expectedFood)
		{
			return true;
		}
		else if (expectedFood == otherBench.expectedFood)
		{
			if (ducksPresent < otherBench.ducksPresent)
			{
				return true;
			}
			else if (ducksPresent > otherBench.ducksPresent)
			{
				return false;
			}
			else
			{
				if (number < otherBench.number)
				{
					return true;
				}
				else return false;
			}
		}
		else
			return false;
	}


};
class Solution
{
public:
	int numberOfBenches;
	vector<Bench> benches;
	void output()
	{
		vector<int> food;
		vector <int> ducks;
		cin >> numberOfBenches;

		for (int i = 0; i < numberOfBenches; i++)
		{
			int f;
			cin >> f;
			food.push_back(f);
		}

		for (int i = 0; i < numberOfBenches; i++)
		{
			int d;
			cin >> d;
			ducks.push_back(d);
		}

		for (int i = 0; i < numberOfBenches; i++)
		{
			Bench bench(ducks[i], food[i], i + 1);
			benches.push_back(bench);
		}

		sort(benches.begin(), benches.end());

		for (int i = 0; i < numberOfBenches; i++)
		{
			cout << benches[i].number << " ";
		}

		cout << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*
3
2 3 2
2 9 1
*/