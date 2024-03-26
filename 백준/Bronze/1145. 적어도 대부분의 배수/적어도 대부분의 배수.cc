#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int arr[5];
int cur_n = 1;

bool is_div(int n)
{
	int cnt = 0;

	for (int i = 0; i < 5; i++)
	{
		if (n % arr[i] == 0)
			cnt++;
	}

	if (cnt >= 3)
		return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	while (true)
	{
		if (is_div(cur_n))
		{
			cout << cur_n;
			break;
		}

		cur_n++;
	}

	return 0;
}