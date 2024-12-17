#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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
int V, E;
vector<bool> vis(3005, false);
vector<int> adj[3005];
//=========================//

void dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (!vis[nxt]) {
			vis[nxt] = true;
			dfs(nxt);
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> V >> E;

	for (int u, v, i = 0; i < E; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int odd = 0;
	for (int i = 1; i <= V; i++) {
		if (adj[i].size() & 1)
			odd++;
	}

	if (!(odd == 0 || odd == 2)) {
		cout << "NO";
		exit(0);
	}

	dfs(1);
	if (count(vis.begin() + 1, vis.begin() + (V + 1), false) > 0) { // 모든 컴포넌트가 이어져 있는지 확인
		cout << "NO";
		exit(0);
	}

	cout << "YES";
}