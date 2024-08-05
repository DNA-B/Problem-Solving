#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/
const int INF = 0x3f3f3f3f;
/****** VARIABLEs ******/
int N, M, S, T;
int d[5005];
vector<pair<int, int>> adj[5005];
priority_queue<pair<int, int>,
	vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
		adj[v].push_back({ cost, u });
	}

	cin >> S >> T;

	fill(d, d + (N + 1), INF);
	d[S] = 0;
	pq.push({ d[S], S });

	while (!pq.empty()) {
		auto [cur_cost, cur] = pq.top();
		pq.pop();

		if (d[cur] != cur_cost)
			continue;

		for (auto [nxt_cost, nxt] : adj[cur]) {
			if (d[nxt] > d[cur] + nxt_cost) {
				d[nxt] = d[cur] + nxt_cost;
				pq.push({ d[nxt], nxt });
			}
		}
	}

	cout << d[T];

	return 0;
}