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
int N, M, R;
int depth[100005];
vector<int> adj[100005];
//=========================//

void dfs(int cur, int dep) {
	depth[cur] = dep;
	for (int nxt : adj[cur]) {
		if (depth[nxt] == -1)
			dfs(nxt, dep + 1);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> R;

	for (int u, v, i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
		sort(adj[i].begin(), adj[i].end());

	memset(depth, -1, sizeof(depth));
	dfs(R, 0);

	for (int i = 1; i <= N; i++)
		cout << depth[i] << '\n';
}