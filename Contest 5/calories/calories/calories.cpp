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


int main()
{
	int items;
	cin >> items;

	int min = 0;
	int max = 0;
	for (int i = 0; i < items; i++)
	{
		int options;
		cin >> options;
		int cal;
		cin >> cal;
		int minimum = cal;
		int maximum = cal;
		for (int j = 1; j < options; j++)
		{
			cin >> cal;
			if (cal > maximum) maximum = cal;
			if (cal < minimum) minimum = cal;

		}
		min += minimum;
		max += maximum;
	}

	cout << min << " " << max << endl;
	return 0;
}

/*
2
3 110 200 150
2 300 700

3
4 50 80 100 0
2 250 100
3 140 70 100
*/