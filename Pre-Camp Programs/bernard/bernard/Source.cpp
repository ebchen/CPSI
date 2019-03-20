/*
ID: eric.ch2
PROG: PROGRAM_NAME
LANG: C++11
*/

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
	int numberOfFish;
	int sightRange;
	vector<int> fish;
public:
	int sum(vector<int> fish)
	{

	}
	void output()
	{
		ifstream fin("bernard.in");
		fin >> numberOfFish;
		fin >> sightRange;
		for (int i = 0; i < numberOfFish; i++)
		{
			int del;
			fin >> del;
			fish.push_back(del);
		}

		int maxSum = fish[0];
		
	}
};

int main()
{
	return 0;
}