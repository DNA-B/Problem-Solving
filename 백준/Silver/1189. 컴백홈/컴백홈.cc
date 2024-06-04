#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10
#define MOD 1'000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int R, C, K;
int res = 0;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int vis[BOUND][BOUND];
char board[BOUND][BOUND];
/***********************/

void solve(int cnt, pair<int, int> cur) {
	if (cnt == K && cur.X == 1 && cur.Y == C)
		res++;
	if (cnt >= K)
		return;


	for (int dir = 0; dir < 4; dir++) {
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];

		if (nx < 1 || nx > R || ny < 1 || ny > C)
			continue;
		if (vis[nx][ny])
			continue;
		if (board[nx][ny] == 'T')
			continue;

		vis[nx][ny] = 1;
		solve(cnt + 1, { nx, ny });
		vis[nx][ny] = 0;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> R >> C >> K;

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> board[i][j];

	vis[R][1] = 1;
	solve(1, { R, 1 });
	cout << res;

	return 0;
}