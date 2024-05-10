#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 101
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, M, R;
int res = 0;
int item[BOUND];
vector<pair<int, int>> adj[BOUND];
/***********************/

int dijk(int st) {
	int total_item = 0;
	int d[BOUND];
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	fill(d, d + BOUND, INT_MAX);

	d[st] = 0;
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (d[cur.Y] != cur.X)
			continue;

		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] > d[cur.Y] + nxt.X) {
				d[nxt.Y] = d[cur.Y] + nxt.X;
				pq.push({ d[nxt.Y], nxt.Y });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		if (d[i] <= M)
			total_item += item[i];
	}

	return total_item;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
		cin >> item[i];

	for (int a, b, l, i = 1; i <= R; i++) {
		cin >> a >> b >> l;
		adj[a].push_back({ l, b });
		adj[b].push_back({ l, a });
	}

	for (int i = 1; i <= N; i++)
		res = max(res, dijk(i));

	cout << res;

	return 0;
}