#include <bits/stdc++.h>

using namespace std;

int N;
int arr[100002];
int mem[100002][2];
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		mem[i][0] = mem[i][1] = arr[i];
	}

	ans = arr[0];
	for (int i = 1; i < N; i++)
	{
		mem[i][0] = max(mem[i - 1][0] + arr[i], arr[i]);
		mem[i][1] = max(mem[i - 1][0], mem[i - 1][1] + arr[i]);
		ans = max({ ans, mem[i][0], mem[i][1] });
	}

	cout << ans;

	return 0;
}