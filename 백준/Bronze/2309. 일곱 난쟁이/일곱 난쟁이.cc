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

	int arr[9];
	int lie1, lie2;
	int left_two = 0;
	bool stop = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		left_two += arr[i];
	}
	left_two -= 100;
	sort(arr, arr + 9);
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = i; j < 9; j++)
		{
			if (arr[i] + arr[j] == left_two)
			{
				lie1 = i;
				lie2 = j;
				stop = 1;
				break;
			}
		}

		if (stop)
		{
			break;
		}
	}
	
	for (int i = 0; i < 9; i++)
	{
		if (i != lie1 && i != lie2)
		{
			cout << arr[i] << "\n";
		}
	}

	return 0;
}