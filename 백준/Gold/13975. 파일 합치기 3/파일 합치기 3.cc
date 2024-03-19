#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int T, N;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--)
	{
		int x;
		long long cnt = 0;
		pq = {};

		cin >> N;

		while (N--)
		{
			int x;

			cin >> x;
			pq.push(x);
		}

		while (pq.size() > 1)
		{
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();

			cnt += (a + b);
			pq.push(a + b);
		}

		cout << cnt << "\n";
	}

	return 0;
}