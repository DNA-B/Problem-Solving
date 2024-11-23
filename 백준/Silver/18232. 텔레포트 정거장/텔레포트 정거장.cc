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
int N, M, S, E;
vector<int> vis(300005, -1);
vector<int> warp[300005];
int dx[] = { 1, -1 };
queue<int> q;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> S >> E;

	for (int u, v, i = 0; i < M; i++) {
		cin >> u >> v;
		warp[u].push_back(v);
		warp[v].push_back(u);
	}

	vis[S] = 0;
	q.push(S);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur == E) {
			cout << vis[cur];
			exit(0);
		}

		if (!warp[cur].empty()) {
			for (int en : warp[cur]) {
				if (vis[en] == -1) {
					vis[en] = vis[cur] + 1;
					q.push(en);
				}
			}
		}

		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];

			if (nx < 1 || nx > N)
				continue;
			if (vis[nx] != -1)
				continue;

			vis[nx] = vis[cur] + 1;
			q.push(nx);
		}
	}
}