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

void pairing_six_nine(int arr[])
{
	if (arr[9] > 0 && arr[6] > 0)
	{
		if (arr[9] < arr[6])
		{
			if ((arr[6] - arr[9]) % 2 == 0)
			{
				arr[6] = (((arr[6] - arr[9]) / 2)) + arr[9];
				arr[9] = 0;
			}
			else
			{
				arr[6] = (((arr[6] - arr[9]) / 2) + 1) + arr[9];
				arr[9] = 0;

			}
		}
		else if (arr[9] > arr[6])
		{
			if ((arr[9] - arr[6]) % 2 == 0)
			{
				arr[9] = (((arr[9] - arr[6]) / 2)) + arr[6];
				arr[6] = 0;
			}
			else
			{
				arr[9] = (((arr[9] - arr[6]) / 2) + 1) + arr[6];
				arr[6] = 0;

			}
		}
	}
	else if (arr[9] > 0)
	{
		if (arr[9] % 2 == 0)
		{
			arr[9] /= 2;
		}
		else
		{
			arr[9] = arr[9] / 2 + 1;
		}
	}
	else if (arr[6] > 0)
	{
		if (arr[6] % 2 == 0)
		{
			arr[6] /= 2;
		}
		else
		{
			arr[6] = arr[6] / 2 + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int set_num[10] = { 0 };
	string door_num;
	int max = -1;
	int index = 0;
	
	cin >> door_num;

	for (char num : door_num)
	{
		set_num[num - '0']++;
	}

	pairing_six_nine(set_num);

	for (int i = 0; i < 10; i++)
	{
		if (set_num[i] != 0)
		{
			if (max < set_num[i])
			{
				max = set_num[i];
			}
		}
	}

	cout << max;

	return 0;
}