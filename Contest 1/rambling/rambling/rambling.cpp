
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
	int numLectures;
	int sum;
	double newTotal;
	double saved;
public:
	void output()
	{
		newTotal = 0;
		saved = 0;
		cin >> numLectures;
		sum = 0;
		for (int i = 0; i < numLectures; i++)
		{
			double rate;
			int duration;
			string name;
			cin >> name;
			cin >> rate;
			cin >> duration;
			sum += duration;
			double newTime = duration / rate;
			newTotal += newTime;
		}
		
		saved = sum - newTotal;
		/*
		int x = (int)saved;
		int count = 1;
		while (x > 9)
		{
			x /= 10;
			count++;
		}
		*/
		//cout.precision(count + 2);
		//cout << saved << endl;
		cout.precision(2);
		cout << fixed << saved << endl;

	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}