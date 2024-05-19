#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 32001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, M;
int deg[BOUND];
vector<int> adj[BOUND];
queue<int>q;
vector<int> res;
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int a, b, i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0)
			q.push(i);
	}

	while (!q.empty()) { // O(V + E), 사이클이 없는 방향그래프에서만 동작 가능
		int cur = q.front();
		q.pop();
		res.push_back(cur);

		for (auto nxt : adj[cur]) {
			deg[nxt]--;

			if (deg[nxt] == 0)
				q.push(nxt);
		}
	}
    
	for (auto x : res)
        cout << x << " ";

	return 0;
}