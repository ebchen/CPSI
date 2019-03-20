#include <vector>
#include <fstream>
#include <math.h>
#include <climits>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <deque>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <utility>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <stack>
#include <bitset>
#include <random>
#include <cstring>
#include <complex>
#include <cassert>

using namespace std;


long long modExp(int base, long long exp, long long mod)
{
	if (exp == 0) return 1 % mod;
	if (exp == 1) return base % mod;

	if (exp % 2 == 0)
	{
		long long sqrt = modExp(base, exp / 2, mod);
		return (sqrt*sqrt) % mod;
	}

	return ((base * modExp(base, exp - 1, mod)) % mod);
}

int main()
{
	long long n;
	long long md = 1000000007;
	cin >> n;

	long long p = modExp(1, n, md);
	long long q = modExp(2, n, md);
	cout << (p+q) % md << endl;
	

	return 0;
}

// 1/3 to win
// 1/3 to tie
// 1/3 to lose