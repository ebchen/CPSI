
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
	vector<int> vacations;

	void output()
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			vacations.push_back(x);
		}

		// prime sieve
		vector<bool> isprime;
		isprime.resize(2000);
		fill(isprime.begin(), isprime.end(), true);
		isprime[0] = false;
		isprime[1] = false;

		for (int i = 2; i * i <= 1100; i++)
			for (int j = 2 * i; j<1100; j += i)
				isprime[j] = false;

		vector<int> primes;

		for (int i = 2; i < isprime.size(); i++)
		{
			if (isprime[i])
				primes.push_back(i);
		}
			
		int counter = 0;
		for (int i = 0; i < n; i++)
		{
			if (vacations[i] == 0 || vacations[i] == 1)
			{
				continue;
			}

			for (int j = 0; j < vacations[i]; j++)
			{
				
				if (vacations[i] % primes[j] == 0)
				{
					int quotient = vacations[i] / primes[j];
					if (find(primes.begin(), primes.end(), quotient) != primes.end())
					{
						counter++;
						break;
					}
				}
			}
		}	

		cout << counter << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*
4
15 22 18 49
*/