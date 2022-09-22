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

	for (int i = 1; i < num; i++)
	{
		for (int k = num; k > num - i; k--)
		{
			cout << "*";
		}

		for (int j = 2 * i - 1; j < 2 * num - 1; j++)
		{
			cout << " ";
		}

		for (int k = num; k > num - i; k--)
		{
			cout << "*";
		}
		cout << "\n";
	}

	for (int i = num; i > 0; i--)
	{
		for (int k = num; k > num - i; k--)
		{
			cout << "*";
		}

		for (int j = 2 * i - 1; j < 2 * num - 1; j++)
		{
			cout << " ";
		}

		for (int k = num; k > num - i; k--)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}