
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
	string input;

	int value(char letter)
	{
		if (letter == 'R') return -1;
		else return 1;
	}

	int value2(char letter)
	{
		if (letter == 'B') return -1;
		else return 1;
	}
	void output() // set the right and move the left.
	{
		cin >> input;
		int start = 0;
		int startingPoint = 0;
		int endingPoint = 0;
		int sum = 0;
		int maximumP = value(input[0]);
		for (int i = 0; i < input.size(); i++)
		{
			sum += value(input[i]);
			if (sum > maximumP)
			{
				maximumP = sum;
				endingPoint = i;
				startingPoint = start;
			}
			if (sum < 0)
			{
				start = i + 1;
				sum = 0;
			}
		}

		//int length = endingPoint - startingPoint;

		start = 0;
		int startingPoint2 = 0;
		int endingPoint2 = 0;
		int sum2 = 0;
		int maximumN = value2(input[0]);

		for (int i = 0; i < input.size(); i++)
		{
			sum2 += value2(input[i]);
			if (sum2 > maximumN)
			{
				maximumN = sum2;
				endingPoint2 = i;
				startingPoint2 = start;
			}
			if (sum2 < 0)
			{
				start = i + 1;
				sum2 = 0;
			}
		}

		if (maximumN > maximumP)
		{
			cout << startingPoint2+1 << " " << endingPoint2+1 << endl;
		}

		else if (maximumN < maximumP)
		{
			cout << startingPoint + 1 << " " << endingPoint + 1 << endl;
		}

		else if (maximumN == maximumP)
		{
			if (startingPoint < startingPoint2)
				cout << startingPoint + 1 << " " << endingPoint + 1 << endl;
			else if (startingPoint2 < startingPoint)
				cout << startingPoint2 + 1 << " " << endingPoint2 + 1 << endl;
			else
			{
				if (endingPoint - startingPoint < endingPoint2-startingPoint2)
					cout << startingPoint + 1 << " " << endingPoint + 1 << endl;
				else
					cout << startingPoint2 + 1 << " " << endingPoint2 + 1 << endl;
			}
		}
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

//BBBBRRRRBBBBB

/*

MCSS


*/