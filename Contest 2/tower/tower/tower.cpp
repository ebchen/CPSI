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
};
// base can't be long long because long long * long long overflows a long long
long long modExp(int base, long long exp, long long mod)
{
	if (exp == 0) return 1 % mod;
	if (exp == 1) return base % mod;

	// Even case where we get time savings
	if (exp % 2 == 0)
	{
		long long sqrt = modExp(base, exp / 2, mod);
		return (sqrt*sqrt) % mod;
	}

	// Regular recursive breakdown.
	return ((base * modExp(base, exp - 1, mod)) % mod);
}
int main()
{
	long long n;
	long long m;
	long long z;

	cin >> n >> m >> z;

	
	cout << modExp(m, n, z) << endl;

	/*
	normal way to write it
	
	long long result = 1LL;
	for (int i = 0; i < n; i++)
	{
		result = (result*m) % z;
	}
	*/

	/*
	mod rules

	m^n % 2 and n is even
	m^n = [m^(n/2) * m^(n/2)] % z
	m^n = [(m^(n/2)%z) * (m^(n/2)%z)] % z
	*/

	return 0;
}



// m pegs
// n disks

/*

Ordering is forced

# of ways to distribute distinguishable n disks into n distinguishable pegs
		each disk m choices
			m^n % z



*/