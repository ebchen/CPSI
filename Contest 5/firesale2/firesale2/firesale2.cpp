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
	int n;
	int maxMoney;
	cin >> n;
	cin >> maxMoney;

	vector<int> toys;
	vector <int> com;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		toys.push_back(x);
	}
	com.resize(n);
	com[0] = toys[0];
	for (int i = 1; i < n; i++)
	{
		com[i] = com[i - 1] + toys[i];
	}

	int maxAmount = 0;

	for (int i = 0; i < n; i++)
	{
		bool found = false;
		for (int j = n-1; j >= i; j--)
		{
			int length = j - i + 1;
			int sum = 0;
			if (i == 0) sum = com[j] - 0;
			else sum = com[j] - com[i-1];
			
			if (length > maxAmount && maxMoney * length >= sum)
			{
				found = true;
				maxAmount = length;
				break;
			}
			
		
		}
	}

	cout << maxAmount << endl;
	return 0;
}

/*


*/