#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N, M, res = 0;
int vis[105];
vector<int> lo[105], hi[105];
//=========================//

int bfs(int st, int mode) {
	int cnt = 0;
	queue<int> q;

	fill(vis, vis + (N + 1), 0);
	q.push(st);
	vis[st] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (mode == 0) {
			for (int nxt : lo[cur]) {
				if (!vis[nxt]) {
					q.push(nxt);
					vis[nxt] = 1;
					cnt++;
				}
			}
		}
		else {
			for (int nxt : hi[cur]) {
				if (!vis[nxt]) {
					q.push(nxt);
					vis[nxt] = 1;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int u, v, i = 0; i < M; i++) {
		cin >> u >> v;
		lo[v].push_back(u); // v는 u보다 작다
		hi[u].push_back(v); // u는 v보다 크다
	}

	const int BOUND = (N - 1) / 2;
	for (int i = 1; i <= N; i++) {
		int n_lo = bfs(i, 0); // i보다 큰 구슬
		int n_hi = bfs(i, 1); // i보다 작은 구슬

		if (n_lo > BOUND || n_hi > BOUND)
			res++;
	}

	cout << res;
	return 0;
}