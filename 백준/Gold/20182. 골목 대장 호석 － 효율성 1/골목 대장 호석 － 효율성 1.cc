#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N, M, A, B, C;
vector<pair<int, int>> adj[100005];
//=========================//

bool dijk(int x) {
	vector<int> d(N + 1, INF);
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>> > pq;

	d[A] = 0;
	pq.push({ d[A], A });
	while (!pq.empty()) {
		auto [cost, cur] = pq.top(); pq.pop();

		if (d[cur] != cost)
			continue;

		for (auto [nxt_cost, nxt] : adj[cur]) {
			int new_cost = d[cur] + nxt_cost;
			if (nxt_cost > x) continue;
			if (new_cost > C || d[nxt] <= new_cost) continue;
			d[nxt] = new_cost;
			pq.push({ d[nxt], nxt });
		}
	}

	return d[B] != INF;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> A >> B >> C;

	for (int u, v, cost, i = 0; i < M; i++) {
		cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
		adj[v].push_back({ cost, u });
	}

	int lo = 0, hi = 25;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (dijk(mid)) hi = mid;
		else lo = mid;
	}

	cout << (hi == 25 ? -1 : hi);
}