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

int gcd(int  a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	if (a == b)
		return a;
	if (a > b) return gcd(a - b, b);
	return gcd(a, b - a);
}

int main()
{

	ios::sync_with_stdio(0); cin.tie(0);
	int operations;
	int total = 0;
	cin >> operations;
	unordered_map<string, int> names;
	for (int i = 0; i < operations; i++)
	{
		int x;
		cin >> x;
		string name;
		cin >> name;

		if (x == 1)
		{
			total++;
			if (names.count(name) > 0)
			{
				names.at(name)++;
			}
			else
			{
				pair<string, int> y= { name, 1 };
				names.insert(y);
			}
		}
		else
		{
			if (names.count(name) > 0)
			{
				int p = names.find(name)->second;
				int q = total;

				int g = gcd(p, q);

				cout << p / g << "/" << q / g << endl;
			}

			else
			{
				cout << "0/1" << endl;
			}



			

		}
	}
	return 0;
}