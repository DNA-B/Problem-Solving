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
int T, N, M, L;
int vis[10005];
vector<int> dominos[10005];
//=========================//

void dfs(int cur) {
	for (int nxt : dominos[cur]) {
		if (!vis[nxt]) {
			vis[nxt] = 1;
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

	cin >> T;

	while (T--) {
		cin >> N >> M >> L;

		int u, v;
		for (int i = 0; i < M; i++) {
			cin >> u >> v;
			dominos[u].push_back(v);
		}

		int x;
		for (int i = 0; i < L; i++) {
			cin >> x;
			if (!vis[x]) {
				vis[x] = 1;
				dfs(x);
			}
		}

		cout << count(vis + 1, vis + (N + 1), 1) << '\n';

		fill(dominos + 1, dominos + N + 1, vector<int>());
		fill(vis + 1, vis + N + 1, 0);
	}
}