
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
private:
	string a;
	string b;
	int counter;
	int index;
public:
	void output()
	{
		ifstream fin("video.in");
		fin >> a;
		fin >> b;
		counter = 0;
		index = 0;
		ofstream fout("video.out");
		bool s = false;
		while (index < b.length())
		{
			for (int i = b.length(); i > 0; i--)
			{
				string sub = b.substr(index, i);
				if (a.find(sub) != string::npos)
				{
					counter++;
					index += i;
					s = true;
					break;

				}


			}
			if (!s)
			{
				fout << -1;
				return;
			}
		
		}
		fout << counter;
		return;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}