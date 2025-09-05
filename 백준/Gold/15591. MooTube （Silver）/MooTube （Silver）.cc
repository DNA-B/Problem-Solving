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
int N, Q;
int vis[5005];
vector<pair<int, int>> adj[5005];
queue<int> q;
//=========================//

int bfs(int st, int k) {
	int ret = 0;

	vis[st] = INT_MAX - 1;
	q.push(st);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto [nxt, r] : adj[cur]) {
			if (vis[nxt] == INT_MAX) {
				vis[nxt] = min(r, vis[cur]);
				ret += (vis[nxt] >= k);
				q.push(nxt);
			}
		}
	}

	return ret;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> Q;

	int st, en, r;
	for (int i = 0; i < N - 1; i++) {
		cin >> st >> en >> r;
		adj[st].push_back({ en, r });
		adj[en].push_back({ st, r });
	}

	int k, v;
	while (Q--) {
		fill(vis, vis + N + 1, INT_MAX);
		cin >> k >> v;
		cout << bfs(v, k) << '\n';
	}
}