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
int N, cnt = 0;
int color[200005], vis[200005];
vector<int> adj[200005];
stack<int> st;
//=========================//

void dfs() {
	if (color[1]) // 루트가 색이 칠해져 있으면 처음부터 한 번 칠해야 함
		cnt++;

	vis[1] = 1;
	st.push(1);
	while (!st.empty()) {
		int cur = st.top(); st.pop();

		for (int nxt : adj[cur]) {
			if (!vis[nxt]) {
				if (color[nxt] != color[cur])
					cnt++;
				vis[nxt] = 1;
				st.push(nxt);
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> color[i];

	for (int u, v, i = 0; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs();
	cout << cnt;
}