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
int N, M, cnt = 0, mx = -1;
int con[10005], vis[10005];
vector<int> adj[10005];
//=========================//

void dfs(int cur) {
	if (adj[cur].empty())
		return;

	for (int nxt : adj[cur]) {
		if (!vis[nxt]) {
			vis[nxt] = 1;
			cnt++;
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

	cin >> N >> M;

	for (int v, u, i = 0; i < M; i++) {
		cin >> v >> u;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= N; i++) {
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		cnt = 0;
		dfs(i);
		con[i] = cnt;
	}

	mx = *max_element(con + 1, con + N + 1);

	for (int i = 1; i <= N; i++) {
		if (con[i] == mx)
			cout << i << ' ';
	}
}