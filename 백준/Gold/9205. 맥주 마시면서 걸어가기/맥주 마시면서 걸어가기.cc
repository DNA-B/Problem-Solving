#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
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
int T, N;
pair<int, int> xy[105];
vector<int> adj[105];
//=========================//

bool bfs(int st) {
	int vis[105] = { 0, };
	queue<int> q;

	q.push(st);
	vis[st] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (auto nxt : adj[cur]) {
			if (!vis[nxt]) {
				q.push(nxt);
				vis[nxt] = 1;
			}
		}
	}

	return vis[N + 1];
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		cin >> N;

		cin >> xy[0].X >> xy[0].Y;
		for (int i = 1; i <= N; i++)
			cin >> xy[i].X >> xy[i].Y;
		cin >> xy[N + 1].X >> xy[N + 1].Y;

		for (int i = 0; i < N + 1; i++) {
			auto [x1, y1] = xy[i];
			for (int j = i + 1; j < N + 2; j++) {
				auto [x2, y2] = xy[j];
				if (abs(x1 - x2) + abs(y1 - y2) <= 20 * 50) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		cout << (bfs(0) ? "happy\n" : "sad\n");
		fill(adj, adj + N + 2, vector<int>());
	}
}