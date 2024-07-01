#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int K, V, E;
bool flag = false;
int color[BOUND];
vector<int> adj[BOUND];
/***********************/

void init() {
	for (int i = 1; i <= V; i++)
		adj[i].clear();

	fill(color, color + (V + 1), 0);
}

void dfs(int cur) {
	if (flag)
		return;

	for (int nxt : adj[cur]) {
		if (!color[nxt]) {
			color[nxt] = -color[cur]; // 자식은 부모 색이랑 반대 색으로 색칠
			dfs(nxt);
		}
		else if (color[cur] == color[nxt]) { // 한 변의 양 끝점이 같은 색이라면 이분 그래프가 아니다.
			flag = true;
			return;
		}
	}
}

bool solve() {
	for (int u, v, i = 0; i < E; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= V; i++) {
		if (!color[i]) {
			color[i] = 1;
			dfs(i);
		}

		if (flag)
			return false;
	}

	return true;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> K;

	while (K--) {
		flag = false;
		cin >> V >> E;
		init();
		cout << (solve() ? "YES\n" : "NO\n");
	}

	return 0;
}