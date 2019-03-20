#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <unordered_set>
#include <deque>
using namespace std;

class Solution
{
public:
	int attributes;
	int cards;
	unordered_set<long long> deck;
	vector<long long> deckArray;
	void output()
	{
		cin >> attributes;
		cin >> cards;

		for (int i = 0; i < cards; i++)
		{
			long long cardValue = 0;
			for (int i = 0; i < attributes ; i++)
			{
				int trait;
				cin >> trait;
				cardValue = cardValue * 10 + (trait + 1);
			}

			deck.insert(cardValue);
			deckArray.push_back(cardValue);
		}
		long long setCount = 0;
		for (int i = 0; i < cards-1; i++)
		{
			for (int j = i+1; j < cards; j++)
			{
				long long card1 = deckArray[i];
				long long card2 = deckArray[j];
				
				long long newNumber = 0;
				deque<int> number;
				for (int k = 0; k < attributes; k++)
				{
					int trait1 = card1 % 10;
					card1 /= 10;
					
					int trait2 = card2 % 10;
					card2 /= 10;

					
					if (trait1 == trait2)
					{
						number.push_front(trait1);
						//newNumber = newNumber + trait1 * 10;
					}
					else
					{
						if (trait1 == 1 && trait2 == 2) number.push_front(3);//newNumber = newNumber  + 3 * 10;
						else if (trait1 == 1 && trait2 == 3) number.push_front(2);//newNumber = newNumber + 2 * 10;
						else if (trait1 == 2 && trait2 == 1) number.push_front(3);//newNumber = newNumber + 3 * 10;
						else if (trait1 == 2 && trait2 == 3) number.push_front(1);//newNumber = newNumber + 1 * 10;
						else if (trait1 == 3 && trait2 == 2) number.push_front(1);//newNumber = newNumber  + 1 * 10;
						else if (trait1 == 3 && trait2 == 1) number.push_front(2);//newNumber = newNumber  + 2 * 10;
					}
				}

				while (!number.empty())
				{
					int digit = number.front();
					newNumber = newNumber * 10 + digit;
					number.pop_front();
				}

				unordered_set<long long>::const_iterator it = deck.find(newNumber);
				if (it != deck.end())
				{
					setCount++;
				}
			}
		}

		cout << setCount/3 << endl;
	}

};

int main()
{
	Solution solution;
	solution.output();
	return 0;
}

/*

store cards in a bitmask. Need to use a long long instead of int.


store each card in a Hash Set
if you know 2 cards, then a unique 3rd card is its match.

Double for loop:
	Go through each pair of cards
		1. calculate its match
		2. is the match in the set of cards
				* slow way is a full for loop
			*use a Hash Set and call .contain()

			

*/

/*
3 3
0 1 2
0 2 2 
0 0 2
*/

/*
4 7
0 0 0 1
0 0 1 0
1 0 0 1
2 0 2 2
2 0 0 1
2 0 1 0
1 1 1 1

*/