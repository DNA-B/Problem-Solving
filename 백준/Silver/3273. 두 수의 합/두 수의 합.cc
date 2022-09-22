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

int freq[1000001] = { 0 };
int arr[100001] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int x;
	int count = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		freq[arr[i]]++;
	}

	cin >> x;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < x && x - arr[i] < 1000000)
		{
			if (arr[i] != x - arr[i])
			{
				if (freq[x - arr[i]] > 0)
				{
					count++;
					freq[arr[i]] = 0;
				}
			}

		}
	}

	cout << count;

	return 0;
}