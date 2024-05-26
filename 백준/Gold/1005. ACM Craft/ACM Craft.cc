#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 1001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int T, N, K, W;
int res = 0;
int D[BOUND];
int mem[BOUND];
int deg[BOUND];
/***********************/

void init() {
	res = 0;
	fill(mem, mem + (N + 1), 0);
	fill(deg, deg + (N + 1), 0);
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		vector<int> adj[BOUND];
		queue<int> q;

		init();
		cin >> N >> K;

		for (int i = 1; i <= N; i++)
			cin >> D[i];

		for (int x, y, i = 1; i <= K; i++) {
			cin >> x >> y;

			adj[x].push_back(y);
			deg[y]++;
		}

		for (int i = 1; i <= N; i++) {
			if (deg[i] == 0) {
				mem[i] = D[i];
				q.push(i);
			}
		}

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			for (auto nxt : adj[cur]) {
				deg[nxt]--;
				mem[nxt] = max(mem[nxt], mem[cur] + D[nxt]);

				if (deg[nxt] == 0)
					q.push(nxt);
			}
		}

		cin >> W;
		cout << mem[W] << "\n";
	}

	return 0;
}