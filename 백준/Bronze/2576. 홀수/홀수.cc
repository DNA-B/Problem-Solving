#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm> 
// #include <string> 
// #include <cctype> 
// #include <cmath> 
// #include <queue>
// #include<deque>
// #include <set>
// #include <vector>
// #include <stack> 
// #include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[7] = { 0 };
	int sum = 0;
	int min_odd = 101;

	for (int i = 0; i < 7; i++)
	{
		cin >> arr[i];

		if ((arr[i] % 2) != 0)
		{
			sum += arr[i];

			if (min_odd > arr[i])
			{
				min_odd = arr[i];
			}
		}
	}

	if (min_odd == 101)
	{
		cout << -1;
	}
	else
	{
		cout << sum << "\n" << min_odd;
	}
	
	return 0;
}