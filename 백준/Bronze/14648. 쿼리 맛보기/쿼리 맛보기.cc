#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long arr[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> Q;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	int order, a, b, c, d;
	while (Q--)
	{
		cin >> order;

		if (order == 1)
		{
			cin >> a >> b;
			cout << accumulate(arr + a, arr + b + 1, 0LL) << "\n";
			swap(arr[a], arr[b]);
		}
		else
		{
			cin >> a >> b >> c >> d;
			cout << accumulate(arr + a, arr + b + 1, 0LL) - accumulate(arr + c, arr + d + 1, 0LL) << "\n";
		}

	}

	return 0;
}