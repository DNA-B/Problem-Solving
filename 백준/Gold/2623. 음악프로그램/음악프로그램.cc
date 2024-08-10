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
int N, M;
int deg[1001];
vector<int> adj[1001];
vector<int> res;
queue<int> q;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	int s, u, v;
	for (int i = 0; i < M; i++) {
		cin >> s >> u;
		for (int i = 0; i < s - 1; i++) {
			cin >> v;
			adj[u].push_back(v);
			deg[v]++;
			u = v;
		}
	}

	for (int i = 1; i <= N; i++)
		if (deg[i] == 0) q.push(i);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		res.push_back(cur);

		for (auto nxt : adj[cur]) {
			deg[nxt]--;
			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	if (res.size() != N) {
		cout << 0;
		exit(0);
	}

	for (auto x : res)
		cout << x << "\n";

	return 0;
}