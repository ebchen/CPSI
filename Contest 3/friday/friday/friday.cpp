#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <utility>  
using namespace std;



class Solution
{
public:
	int n;
	int m;
	vector <int> students;
	vector < int> buildings;
	vector<pair<int,int>> students2;

	Solution()
	{
		cin >> n;
		cin >> m;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			pair<int, int> s;
			s.first = x;
			s.second = i;
			students2.push_back(s);
			students.push_back(x);
		}

		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			buildings.push_back(x);
		}

		sort(buildings.begin(), buildings.end());
		sort(students2.begin(), students2.end());
		fill(students.begin(), students.end(), -1);
	}
	void output()
	{
		

		int counter = 0;
		for (int i = 0; i < n; i++)
		{
			int sT = students2[i].first;
			int sID = students2[i].second;
			for (int j = counter; j < m; j++)
			{
				bool limit = false;
				if (buildings[j] >= sT)
				{
					limit = true;
				}
				else counter++;
				if (limit == true)
				{
					students[sID] = counter;
					break;
				}
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			if (students[i] == -1)
			{
				cout << 0 << " ";
			}
			else  cout << m - students[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}


/*

ONlogN complexity

for loop of N
	inside is OlogN

Resort items and remember original index

Put old and new IDs in an array
*/
/*
6 4
3 1 4 2 5 6
3 5 2 8



7 5
7 9 2 1 4 2 2
8 2 1 3 3

*/