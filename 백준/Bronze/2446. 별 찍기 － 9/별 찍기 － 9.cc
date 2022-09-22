#include <iostream>
#include <algorithm> 
// #include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
 #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;

	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j < i; j++)
		{
			cout << " ";
		}

		for (int k = 1; k <= 2 * (num - i) + 1; k++)
		{
			cout << "*";
		}

		cout << "\n";
	}

	for (int i = num - 1; i > 0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			cout << " ";
		}

		for (int k = 1; k <= 2 * (num - i) + 1; k++)
		{
			cout << "*";
		}

		cout << "\n";
	}

	return 0;
}