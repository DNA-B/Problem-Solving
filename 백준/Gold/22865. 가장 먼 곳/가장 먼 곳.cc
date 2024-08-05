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
const ll LLINF = 1e18;
/****** VARIABLEs ******/
int N, M, A, B, C, mx = -1, mx_idx = -1;
int d[3][100005]; // A, B, C 각각의 dist
vector<pair<int, int>> adj[100005];
/***********************/

void dijk(int st, int idx) {
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;

	fill(d[idx], d[idx] + (N + 1), INF);
	d[idx][st] = 0;
	pq.push({ d[idx][st], st });

	while (!pq.empty()) {
		auto [cur_cost, cur] = pq.top(); pq.pop();

		if (d[idx][cur] != cur_cost)
			continue;

		for (auto [nxt_cost, nxt] : adj[cur]) {
			if (d[idx][nxt] > d[idx][cur] + nxt_cost) {
				d[idx][nxt] = d[idx][cur] + nxt_cost;
				pq.push({ d[idx][nxt], nxt });
			}
		}
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> A >> B >> C >> M;

	for (int i = 0; i < M; i++) {
		int d, e, l;
		cin >> d >> e >> l;
		adj[d].push_back({ l, e });
		adj[e].push_back({ l, d });
	}

	dijk(A, 0); dijk(B, 1); dijk(C, 2);

	for (int i = 1; i <= N; i++) {
		if (i == A || i == B || i == C)
			continue;
		if (int tmp = min({ d[0][i], d[1][i], d[2][i] }); tmp > mx) {
			mx = tmp;
			mx_idx = i;
		}
	}

	cout << mx_idx;
	return 0;
}