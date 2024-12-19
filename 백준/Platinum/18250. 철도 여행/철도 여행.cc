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
int N, M, res = 0;
int vis[200005];
vector<int> comp, adj[200005];
//=========================//

void dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (!vis[nxt]) {
			comp.push_back(nxt);
			vis[nxt] = 1;
			dfs(nxt);
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int u, v, i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (!vis[i] && adj[i].size() > 0) {
			comp.clear();
			comp.push_back(i);
			vis[i] = 1;
			dfs(i);

			int odd = 0;
			for (int node : comp)
				odd += (adj[node].size() & 1);

			if (odd == 0 || odd == 2) res++;
			else res += odd / 2;
		}
	}

	cout << res;
}