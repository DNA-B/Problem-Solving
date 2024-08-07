#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
ll d[501];
vector<pair<int, int>> adj[501];
/***********************/

bool bellman(int st) {
	d[st] = 0;
	for (int i = 1; i <= N; i++) { // 원래 N-1번 갱신인데 N번째에 갱신일어나면 cycle 발생
		for (int cur = 1; cur <= N; cur++) {
			for (auto [nxt_cost, nxt] : adj[cur]) {
				if (d[cur] != LL_INF && d[nxt] > d[cur] + nxt_cost) {
					if (i == N) return false; // negative cycle
					d[nxt] = d[cur] + nxt_cost;
				}
			}
		}
	}
	return true;
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	fill(d + 1, d + (N + 1), LL_INF);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}

	if (!bellman(1)) {
		cout << -1;
		exit(0);
	}

	for (int i = 2; i <= N; i++)
		cout << (d[i] == LL_INF ? -1 : d[i]) << "\n";

	return 0;
}