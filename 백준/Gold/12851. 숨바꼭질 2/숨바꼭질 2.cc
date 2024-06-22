#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, K;
int cnt = 0;
int dx[] = { 0, 1, -1 };
int vis[BOUND];
queue<int> q;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	fill(vis, vis + BOUND, -1);
	vis[N] = 0;
	q.push(N);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		dx[0] = cur;

		if (cur == K) {
			cnt++;
			continue;
		}

		for (int dir = 0; dir < 3; dir++) {
			int nx = cur + dx[dir];

			if (nx < 0 || nx > 100000)
				continue;
			if ((vis[nx] != -1) && (vis[cur] + 1 != vis[nx]))
				continue;

			vis[nx] = vis[cur] + 1;
			q.push(nx);
		}
	}

	cout << vis[K] << "\n" << cnt;

	return 0;
}