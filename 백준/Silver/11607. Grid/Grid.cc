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
char board[501][501];
int vis[501][501];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		fill(vis[i] + 1, vis[i] + (M + 1), -1);
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
	}

	vis[1][1] = 0;
	q.push({ 1, 1 });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int w = (board[cur.X][cur.Y] - '0');

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir] * w;
			int ny = cur.Y + dy[dir] * w;

			if (nx < 1 || nx > N || ny < 1 || ny > M)
				continue;
			if (vis[nx][ny] != -1)
				continue;

			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}

	if (vis[N][M] == -1)
		cout << "IMPOSSIBLE";
	else
		cout << vis[N][M];

	return 0;
}