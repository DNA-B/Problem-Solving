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
int T, N, M;
int arr[505], idx[505], deg[505];
vector<int> adj[505];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		vector<int> res;
		queue<int> q;

		cin >> N;

		fill(arr, arr + (N + 1), 0);
		fill(idx, idx + (N + 1), 0);
		fill(deg, deg + (N + 1), 0);
		for (int i = 1; i <= N; i++)
			adj[i].clear();

		for (int x, i = 0; i < N; i++) {
			cin >> arr[i];
			idx[arr[i]] = i;
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				adj[arr[i]].push_back(arr[j]);
				deg[arr[j]]++;
			}
		}

		cin >> M;

		for (int a, b, i = 0; i < M; i++) {
			cin >> a >> b;

			if (idx[a] < idx[b])
				swap(a, b);

			adj[b].erase(find(adj[b].begin(), adj[b].end(), a));
			deg[a]--;
			adj[a].push_back(b);
			deg[b]++;
		}

		for (int i = 0; i < N; i++)
			if (deg[arr[i]] == 0) q.push(arr[i]);

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			res.push_back(cur);

			for (int nxt : adj[cur]) {
				deg[nxt]--;
				if (deg[nxt] == 0) q.push(nxt);
			}
		}

		if (res.size() != N) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		for (int x : res)
			cout << x << ' ';
		cout << '\n';
	}

	return 0;
}