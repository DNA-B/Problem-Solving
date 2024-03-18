#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, x, cnt = 0;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--)
	{
		int x;

		cin >> x;
		pq.push(x);
	}

	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		cnt += (a + b);
		pq.push(a + b);
	}

	cout << cnt;

	return 0;
}