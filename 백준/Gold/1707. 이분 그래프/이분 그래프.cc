#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 20001
#define MOD 1'000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int K, V, E;
int color[BOUND];
vector<int> adj[BOUND];
/***********************/

void init() {
	for (int i = 1; i <= V; i++)
		adj[i].clear();

	fill(color, color + (V + 1), 0);
}

void dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (!color[nxt]) {
			color[nxt] = -color[cur]; // 자식은 부모 색이랑 반대 색으로 색칠
			dfs(nxt);
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
	}

	for (int i = 1; i <= V; i++) {
		for (int nxt : adj[i])
			if (color[i] == color[nxt]) // 한 변의 양 끝점이 같은 색이라면 이분 그래프가 아니다.
				return false;
	}

	return true;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> K;

	while (K--) {
		cin >> V >> E;
		init();
		cout << (solve() ? "YES\n" : "NO\n");
	}

	return 0;
}