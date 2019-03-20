
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
	int n;
	priority_queue<int,vector<int>,greater<int>> numbers;
	//vector<long> pfNumbers;
	//vector<long> ogNumbers;
	void output()
	{
		cin >> n;
		
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			numbers.push(x);
		}
/*
		sort(ogNumbers.begin(), ogNumbers.end());

		
		for (int i = 0; i < ogNumbers.size(); i++)
		{
			pfNumbers.push_back(ogNumbers[i]);
		}
		

		//prefix
		for (int i = 0; i < n; i++)
		{
			if (i > 0)
				pfNumbers[i] += pfNumbers[i - 1];

		}
		*/
		int time = 0;
		while (!numbers.empty())
		{
			if (numbers.size() == 2)
			{

				int y = numbers.top();
				numbers.pop();
				y += numbers.top();
				time += y;
				break;
			}
			int least = numbers.top();
			numbers.pop();

			least += numbers.top();
			numbers.pop();
			
			numbers.push(least);

			time += least;
		}
		

		cout <<  time << endl;

	}
	
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}