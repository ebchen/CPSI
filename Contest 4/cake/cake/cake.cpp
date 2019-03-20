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

/*
pair<long long, long long> formula(long long width, long long length, long long heightA, long long heightB)
{
	long long t = width * length * heightB;
	long long side1 = heightA * width * 2;
	long long side2 = heightA * length * 2;

	pair<long long, long long> frac = { t + side1 + side2, heightB };
	return frac;
}

pair <long long, long long> volume(long long width, long long length, long long heightA, long long heightB)
{
	pair<long long, long long> frac = { width*length*heightA, heightB };
	return frac;
}*/

long long gcd(long long a, long long b)
{
	if (a == 0 || b == 0)
		return 0;
	if (a == b)
		return a;
	if (a > b) return gcd(a - b, b);
	return gcd(a, b - a);
}

int gcdArup(int a, int b)
{
	return b == 0 ? a : gcdArup(b, a%b);
}


int main()
{
	long long W;
	long long L;
	long long numerator;
	long long denominator;

	cin >> W;
	cin >> L;
	cin >> numerator;
	cin >> denominator;

	long long hcf = gcd(numerator, denominator);
	numerator /= hcf;
	denominator /= hcf;
	
	long long C = denominator * W*L;
	long long D = numerator * W*L - denominator * (2 * W + 2 * L);
	
	

	long long h = gcd(C, D);
	C /= h;
	D /= h;

	cout << C << " " << D << endl;
	
	


	return 0;
}


/*



*/