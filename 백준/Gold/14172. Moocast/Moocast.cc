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
int N, mx = -1;
int vis[205];
tuple<int, int, int> cows[205];
vector<int> adj[205];
//=========================//

int dfs(int cur) {
	int cnt = 1;

	for (int nxt : adj[cur]) {
		if (!vis[nxt]) {
			vis[nxt] = 1;
			cnt += dfs(nxt);
		}
	}

	return cnt;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int x, y, p;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> p;
		cows[i] = { x, y, p };
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			auto [x1, y1, p1] = cows[i];
			auto [x2, y2, p2] = cows[j];

			int dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);

			if (dist <= p1 * p1)
				adj[i].push_back(j);
			if (dist <= p2 * p2)
				adj[j].push_back(i);
		}
	}

	for (int i = 0; i < N; i++) {
		fill(vis, vis + N, 0);
		vis[i] = 1;
		mx = max(mx, dfs(i));
	}

	cout << mx;
}