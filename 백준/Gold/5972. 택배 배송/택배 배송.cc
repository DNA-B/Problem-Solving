#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
int d[50001];
vector<pair<int, int>> adj[50001];
priority_queue<pair<int, int>,
	vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
/***********************/

void dijk(int st) {
	d[st] = 0;
	pq.push({ st, 0 });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (d[cur.X] != cur.Y)
			continue;

		for (auto nxt : adj[cur.X]) {
			if (d[nxt.X] > d[cur.X] + nxt.Y) {
				d[nxt.X] = d[cur.X] + nxt.Y;
				pq.push({ nxt.X, d[nxt.X] });
			}
		}
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	fill(d + 1, d + (N + 1), INF);

	for (int i = 0; i < M; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ v,  cost });
		adj[v].push_back({ u,  cost });
	}

	dijk(1);
	cout << d[N];

	return 0;
}