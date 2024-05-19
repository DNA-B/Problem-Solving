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
vector<int> res;
priority_queue<int,
	vector<int>,
	greater<int>>pq; // 쉬운 문제부터 풀어야하므로 priority_queue 사용
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
			pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		res.push_back(cur);

		for (auto nxt : adj[cur]) {
			deg[nxt]--;

			if (deg[nxt] == 0)
				pq.push(nxt);
		}
	}

	for (auto x : res)
		cout << x << " ";

	return 0;
}