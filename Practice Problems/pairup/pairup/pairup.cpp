#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <set>
using namespace std;

class Cows
{
public:
	int population;
	int output;
	
	Cows(int population, int output)
	{
		this->population = population;
		this->output = output;
	}

	bool operator< (const Cows& otherCow) const
	{
		if (output < otherCow.output) return true;
		else return false;
	}
};
class Solution
{
public:
	
	int n;
	vector <Cows> cows;
	int greatestTime = 0;

	void output()
	{
		//ifstream fin;
		//fin.open("pairup.in");
		//fin >> n;
		greatestTime = 0;
		
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x;
			cin >> y;
			//fin >> x;
			//fin >> y;
			Cows c(x, y);
			cows.push_back(c);
		}

		sort(cows.begin(), cows.end());

		

		while(cows.size() > 0)
		{
			int cow1;
			int cow2;
			
			Cows c = cows[0];
			cow1 = c.output;
			c.population--;
			cows[0] = c;
			if (c.population == 0) cows.erase(cows.begin());

			
			c = cows[cows.size() - 1];
			cow2 = c.output;
			c.population--;
			cows[cows.size() - 1] = c;
			if (c.population == 0) cows.erase(cows.end()-1);

			if (cow1 + cow2 > greatestTime)
			{
				greatestTime = cow1 + cow2;
			}

		}
	//	ofstream fout("pairup.out");
	//	fout << greatestTime << endl;
		cout << greatestTime << endl;
	}

};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}