#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
int cnt = 0;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int board[BOUND][BOUND];
int vis[BOUND][BOUND];
queue<pair<int, int>> q;
/***********************/

void dfs() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = (cur.X + dx[dir] + N) % N;
			int ny = (cur.Y + dy[dir] + M) % M;

			if (vis[nx][ny] || board[nx][ny] == 1)
				continue;

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vis[i][j] || board[i][j] == 1)
				continue;

			vis[i][j] = 1;
			q.push({ i, j });
			dfs();
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}