#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int T, N;
int arr[1002];
int mem[1002];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		for (int i = 1; i <= N; i++)
		{
			mem[i] = arr[i];
			mem[i] = max(mem[i - 1] + arr[i], mem[i]);
		}

		cout << *max_element(mem + 1, mem + (N + 1)) << "\n";
	}

	return 0;
}