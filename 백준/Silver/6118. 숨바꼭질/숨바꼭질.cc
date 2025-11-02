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
int N, M;
int vis[20005];
vector<int> adj[20005];
queue<int> q;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	int u, v;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(vis, -1, sizeof(vis));
	vis[1] = 0;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			if (vis[nxt] == -1) {
				vis[nxt] = vis[cur] + 1;
				q.push(nxt);
			}
		}
	}

	int mx_idx = max_element(vis + 1, vis + (N + 1)) - vis;
	int mx = vis[mx_idx];

	cout << mx_idx << ' ' << mx << ' ' << count(vis + 1, vis + (N + 1), mx);
}