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
int T, N, M, x, y;
bool flag = false;
int vis[1001];
vector<int> adj[1001];
/***********************/

void dfs(int cur) {
	if (flag)
		return;

	for (auto nxt : adj[cur]) {
		if (vis[nxt] == -1) {
			vis[nxt] = (vis[cur] == 1 ? 0 : 1);
			dfs(nxt);
		}
		else if (vis[nxt] == vis[cur]) {
			flag = true;
			return;
		}
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		flag = false;
		cin >> N >> M;

		for (int i = 1; i <= N; i++)
			adj[i].clear();
		fill(vis + 1, vis + (N + 1), -1);

		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		for (int i = 1; i <= N; i++) {
			if (vis[i] == -1) {
				vis[i] = 0;
				dfs(i);
			}

			if (flag)
				break;
		}
		cout << (flag ? "impossible\n" : "possible\n");
	}

	return 0;
}