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
int N, V, E, KI, CR;
int total_d = 0;
int d[2][1001], home[101];
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>,
	vector<pair<int, int>>,
	greater<pair<int, int>>> pq;
/***********************/

void dijk(int ki_or_cr) {
	while (!pq.empty()) {
		auto [cur_cost, cur] = pq.top();
		pq.pop();

		if (d[ki_or_cr][cur] != cur_cost)
			continue;

		for (auto [nxt_cost, nxt] : adj[cur]) {
			if (d[ki_or_cr][nxt] > d[ki_or_cr][cur] + nxt_cost) {
				d[ki_or_cr][nxt] = d[ki_or_cr][cur] + nxt_cost;
				pq.push({ d[ki_or_cr][nxt], nxt });
			}
		}
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> V >> E >> KI >> CR;

	fill(d[0], d[0] + 1001, INF);
	fill(d[1], d[1] + 1001, INF);
	d[0][KI] = d[1][CR] = 0;

	for (int i = 0; i < N; i++)
		cin >> home[i];

	for (int i = 0; i < E; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		adj[a].push_back({ len, b });
		adj[b].push_back({ len, a });
	}

	pq.push({ d[0][KI], KI });
	dijk(0);
	pq.push({ d[1][CR], CR });
	dijk(1);

	for (int rep = 0; rep < 2; rep++) {
		for (int i = 0; i < N; i++)
			total_d += (d[rep][home[i]] == INF ? -1 : d[rep][home[i]]);
	}

	cout << total_d;
	return 0;
}