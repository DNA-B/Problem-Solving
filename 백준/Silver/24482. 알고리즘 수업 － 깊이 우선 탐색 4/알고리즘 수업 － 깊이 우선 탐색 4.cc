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
int N, M, R;
int vis[BOUND];
vector<int> adj[BOUND];
/***********************/

void dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (vis[nxt] == -1) {
			vis[nxt] = vis[cur] + 1;
			dfs(nxt);
		}
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> R;

	while (M--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
		sort(adj[i].begin(), adj[i].end(), greater<>());

	fill(vis + 1, vis + (N + 1), -1);
	vis[R] = 0;
	dfs(R);

	for (int i = 1; i <= N; i++)
		cout << vis[i] << "\n";

	return 0;
}