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
private:
	string word;
	string vowel;
	int vowelCount;
public:
	void output()
	{
		cin >> word;

		vowel = "aeiou";
		vowelCount = 0;
		for (int i = 0; i < word.length(); i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (vowel[j] == word[i])
				{
					vowelCount++;
					break;
				}
			}
		}

		int constCount = word.length() - vowelCount;
		if (vowelCount > constCount) cout << 1 << endl;
		else cout << 0 << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}