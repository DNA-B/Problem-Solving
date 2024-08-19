#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int V, leaf, mx = -1;
int vis[100005];
vector<pair<int, int>> adj[100005];
/***********************/

void dfs(int cur_n, int cur_d) {
	if (cur_d > mx) {
		mx = cur_d;
		leaf = cur_n;
	}

	for (auto [nxt_n, nxt_d] : adj[cur_n]) {
		if (!vis[nxt_n]) {
			vis[nxt_n] = 1;
			dfs(nxt_n, cur_d + nxt_d);
		}
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> V;

	int st, en, dist;
	for (int i = 0; i < V; i++) {
		cin >> st;
		while (1) {
			cin >> en;
			if (en == -1) break;
			cin >> dist;
			adj[st].push_back({ en, dist });
			adj[en].push_back({ st, dist });
		}
	}

	vis[1] = 1;
	dfs(1, 0);
	fill(vis + 1, vis + (V + 1), 0);
	vis[leaf] = 1;
	dfs(leaf, 0);

	cout << mx;
	return 0;
}