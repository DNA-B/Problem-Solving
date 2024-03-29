#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;
long long ans = 0;
priority_queue<long long,
	vector<long long>,
	greater<>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int x, i = 0; i < N; i++)
	{
		cin >> x;
		pq.push(x);
	}

	while (M--)
	{
		long long x, y, total;

		x = pq.top();
		pq.pop();
		y = pq.top();
		pq.pop();
		total = x + y;

		x = y = total;
		pq.push(x);
		pq.push(y);
	}

	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}

	cout << ans;

	return 0;
}