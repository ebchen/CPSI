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
	int R;
	cin >> n;
	cin >> R;

	long long dankness = 0;
	int rec = 0;

	vector<pair<int, int> > memes;
	for (int i = 0; i < n; i++)
	{
		int r;
		int d;
		cin >> r >> d;
		pair <int, int> meme = { r,d };
		memes.push_back(meme);
	}

	sort(memes.begin(), memes.end());


	for (int i = 0; i < n; i++)
	{
		int d = memes[i].second;
		int re = memes[i].first;
		if (rec + re <= R)
		{
			rec += re;
			dankness += d;
		}
	}


	cout << dankness << endl;
	return 0;
}

/*
5 20
1 2
2 1
3 4
4 3
5 5


*/