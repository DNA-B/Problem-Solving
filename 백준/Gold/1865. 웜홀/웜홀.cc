#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 501
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3fLL
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int TC, N, M, W;
int S, E, T;
ll dist[BOUND]; // 최대 (-T * N^2)
vector<pair<int, int>> adj[BOUND];
/***********************/

void init() {
	fill(dist + 1, dist + (N + 1), LLINF);

	for (int i = 1; i <= N; i++)
		adj[i].clear();
}

bool bellman() {
	for (int i = 1; i <= N; i++) { // 원래 N-1 갱신인데 N번째에 갱신일어나면 cycle 발생
		for (int j = 1; j <= N; j++) {
			for (auto nxt : adj[j]) {
				if (dist[nxt.X] > dist[j] + nxt.Y) {
					if (i == N)
						return true;

					dist[nxt.X] = dist[j] + nxt.Y;
				}
			}
		}
	}

	return false;
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> TC;

	while (TC--) {
		cin >> N >> M >> W;
		init();

		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			adj[S].push_back({ E, T });
			adj[E].push_back({ S, T });
		}

		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			adj[S].push_back({ E, -T });
		}

		cout << (bellman() ? "YES\n" : "NO\n");
	}

	return 0;
}