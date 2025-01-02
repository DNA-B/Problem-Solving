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
int V, E, P;
vector<pair<int, int>> adj[5005];
//=========================//

int dijk(int st, int en) {
	vector<int> d(V + 1, INF);
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	d[st] = 0;
	pq.push({ d[st], st });
	while (!pq.empty()) {
		auto [cost, cur] = pq.top(); pq.pop();

		if (d[cur] != cost)
			continue;

		for (auto [nxt_cost, nxt] : adj[cur]) {
			if (d[nxt] > d[cur] + nxt_cost) {
				d[nxt] = d[cur] + nxt_cost;
				pq.push({ d[nxt], nxt });
			}
		}
	}

	return d[en];
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> V >> E >> P;

	for (int a, b, c, i = 0; i < E; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	cout << (dijk(1, P) + dijk(P, V) == dijk(1, V) ? "SAVE HIM" : "GOOD BYE");
}