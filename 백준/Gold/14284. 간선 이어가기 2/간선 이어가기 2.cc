#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
const int INF = 0x3f3f3f3f;
int N, M, S, T;
int d[BOUND];
vector<pair<int, int>> adj[BOUND];
priority_queue<pair<int, int>,
	vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
/***********************/

void dijk() {
	fill(d, d + (N + 1), INF);
	d[S] = 0;
	pq.push({ S, d[S] });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (d[cur.X] != cur.Y)
			continue;

		for (auto nxt : adj[cur.X]) {
			if (d[nxt.X] >= d[cur.X] + nxt.Y) {
				d[nxt.X] = d[cur.X] + nxt.Y;
				pq.push({ nxt.X, d[nxt.X] });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int u, v, cost, i = 0; i < M; i++) {
		cin >> u >> v >> cost;
		adj[u].push_back({ v, cost });
		adj[v].push_back({ u, cost });
	}

	cin >> S >> T;
	dijk();
	cout << d[T];

	return 0;
}