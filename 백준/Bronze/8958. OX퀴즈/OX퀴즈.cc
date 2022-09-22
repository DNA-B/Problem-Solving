#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int score = 0;
	int n;
	int result = 0;

	string ox;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> ox;

		for (int j = 0; j < ox.size(); j++)
		{
			if (ox[j] == 'O')
			{
				score += 1;
				result += score;
			}
			else
			{
				score = 0;
				result += score;
			}
		}
		cout << result << '\n';

		score = 0;
		result = 0;
	}

	return 0;
}