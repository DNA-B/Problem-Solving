#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 21
#define MOD 1'000'000'007
#define PI 3.14159265358979323846
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
int res = 0;
int vis[BOUND];
vector<int> adj[BOUND];
/***********************/

void solve(int cur, int cnt) {
	if (res < cnt)
		res = cnt;
	if (cur >= N)
		return;

	if (!vis[cur]) {
		for (int nxt : adj[cur]) {
			if (!vis[nxt]) {
				vis[nxt] = 1;
				vis[cur] = 1;
				solve(cur + 1, cnt + 2);
				vis[cur] = 0;
				vis[nxt] = 0;
			}
		}
	}

	solve(cur + 1, cnt);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int u, v, i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	solve(1, 0);
	cout << (res < N ? res + 1 : res);

	return 0;
}