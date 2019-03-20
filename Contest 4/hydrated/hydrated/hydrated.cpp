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
	int N;
	cin >> N;

	vector <int> water;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		water.push_back(x);
	}

	vector <int> waterSum;
	waterSum.resize(N);
	waterSum[0] = water[0];
	for (int i = 1; i < N; i++)
	{
		waterSum[i] = waterSum[i - 1] + water[i];
	}

	int overFlow = 0;
	for (int i = 0; i < N; i++)
	{
		int output = (i + 1) * 10 - waterSum[i];
		//overFlow = 0;
		if (output < 0)
		{
			cout << 0 << " ";
		}
		else cout << output << " ";
	}
	cout << endl;

		return 0;
}