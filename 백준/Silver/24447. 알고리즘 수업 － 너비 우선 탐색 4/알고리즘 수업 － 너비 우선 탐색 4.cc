#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
ll res = 0;
int N, M, R, order = 1;
int vis[100005];
vector<int> adj[100005];
//=========================//

void bfs(int st) {
	queue<int> q;

	q.push(st);
	vis[st] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res += (1LL * vis[cur] * (order++)); // depth * order

		for (int nxt : adj[cur]) {
			if (vis[nxt] == -1) {
				vis[nxt] = vis[cur] + 1; // depth
				q.push(nxt);
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> R;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
		sort(adj[i].begin(), adj[i].end());

	memset(vis, -1, sizeof(vis));
	bfs(R);
	cout << res;
}