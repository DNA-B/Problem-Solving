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
int N;
int vis[105];
vector<int> adj[105];
//=========================//

void dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (!vis[nxt]) {
			vis[nxt] = 1;
			dfs(nxt);
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int u, v;
	for (int i = 0; i < N; i++) {
		cin >> u >> v;
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		memset(vis, 0, sizeof(vis));
		vis[i] = 1; dfs(i);
		if (count(vis + 1, vis + N + 1, 1) == N) {
			cout << i;
			exit(0);
		}
	}

	cout << -1;
}