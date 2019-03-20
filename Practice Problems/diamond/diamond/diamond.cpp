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
	int n;
	int range;
	vector<int> diamonds;

	void output()
	{
		ifstream fin("diamond.in");
		fin >> n;
		fin >> range;
		//cin >> n;
		//cin >> range;

		ofstream fout("diamond.out");
		if (n == 0)
		{
			//cout << 0 << endl;
			fout << 0 << endl;
			return;
		}
		if (n == 1)
		{
			//cout << 1 << endl;
			fout << 1 << endl;
			return;
		}

		if (range == 0)
		{
			//cout << 2 << endl;
			fout << 2 << endl;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			int size;
			fin >> size;
			//cin >> size;
			diamonds.push_back(size);
		}

		sort(diamonds.begin(), diamonds.end());

		int leastPt = 0;
		int mostPt = 0;
		int largest = 0;
		int largestLeast = 0;
		int largestMost = 0;
		while (leastPt != n-1 && mostPt != n-1)
		{
			int smallestSize = diamonds[leastPt];
			int largestSize = diamonds[mostPt];

			int diamondsInRange = mostPt - leastPt + 1;
			if (diamondsInRange > largest && largestSize - smallestSize <= range)
			{
				//cout << largestSize - smallestSize << endl;
				//cout << "range " << range << endl;
				//cout << "largest used to be " << largest << endl;
				largest = diamondsInRange;
				//cout << "now it is " << largest << endl;
				largestLeast = leastPt;
				largestMost = mostPt;
				//cout << "index range from" << largestLeast << " to " << largestMost << endl;
			}
			
			if (largestSize - smallestSize <= range)
			{
				mostPt++;
			}

			else if (largestSize - smallestSize > range)
			{
				leastPt++;
			}
		}

		diamonds.erase(diamonds.begin() + leastPt , diamonds.begin() + mostPt );

		leastPt = 0;
		mostPt = 0;
		int largest2 = 0;
		while (leastPt != diamonds.size()-1 && mostPt != diamonds.size() - 1)
		{
			int smallestSize = diamonds[leastPt];
			int largestSize = diamonds[mostPt];

			int diamondsInRange = mostPt - leastPt + 1;
			if (diamondsInRange > largest2 && largestSize - smallestSize <= range)
			{
				largest2 = diamondsInRange;
			}

			if (largestSize - smallestSize <= range)
			{
				mostPt++;
			}

			if (largestSize - smallestSize > range)
			{
				leastPt++;
			}
		}

		
		fout << largest + largest2 << endl;
		//cout << largest + largest2 << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*
7 3
10
5
1
12
9
5
14


*/