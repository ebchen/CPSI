
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
	int num;
	long long numberOfDivisors;
	long long product;
	vector <long long> candidates;
	long long answer;
public:
	void output()
	{
		product = 1;
		cin >> num;
		cin >> numberOfDivisors;
		if (numberOfDivisors == 1)
		{
			cout << 1 << endl;
			return;
		}
		for (int i = 0; i < num; i++)
		{
			int x;
			cin >> x;
			product *= x;
		}
		answer = 0;
		for (int i = 1; i <= product / 2; i++)
		{
			long long productDivisorCount = 0;
			if (product % i == 0)
			{
				productDivisorCount++;
				long divCount = 1;
				for (int j = 1; j <= i / 2; j++)
				{
					if (i % j == 0)
					{
						divCount++;
					}
				}
				if (divCount == numberOfDivisors)
				{
					answer++;
				}
				
			}
			if (productDivisorCount == numberOfDivisors) answer++;
		}
		
		cout << answer << endl;
		
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*

prime factoriization

number of divisors <= cube root (N)

of k > 10^14, print 0
*/