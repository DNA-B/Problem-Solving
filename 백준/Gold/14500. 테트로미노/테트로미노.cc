#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 501
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, M, ans = 0;
int board[BOUND][BOUND], vis[BOUND][BOUND];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
/***********************/

void check_special_shape(pair<int, int> xy) {
	int x = xy.X, y = xy.Y;

	if (x - 1 >= 0 and y - 1 >= 0 and x + 1 < N) // ㅓ
		ans = max(ans, (board[x - 1][y] + board[x][y - 1] + board[x][y] + board[x + 1][y]));
	if (x - 1 >= 0 and y + 1 < M and x + 1 < N) // ㅏ
		ans = max(ans, (board[x - 1][y] + board[x][y + 1] + board[x][y] + board[x + 1][y]));
	if (y - 1 >= 0 and y + 1 < M and x + 1 < N) // ㅗ
		ans = max(ans, (board[x][y] + board[x + 1][y] + board[x + 1][y - 1] + board[x + 1][y + 1]));
	if (y - 1 >= 0 and y + 1 < M and x + 1 < N) // ㅜ
		ans = max(ans, (board[x][y - 1] + board[x][y] + board[x][y + 1] + board[x + 1][y]));
}

void solve(pair<int, int> xy, int cnt, int cur) {
	if (cnt == 4) {
		ans = max(ans, cur);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = xy.X + dx[dir];
		int ny = xy.Y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		if (vis[nx][ny])
			continue;

		vis[nx][ny] = 1;
		solve({ nx, ny }, cnt + 1, cur + board[nx][ny]);
		vis[nx][ny] = 0;
	}

	check_special_shape(xy);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			vis[i][j] = 1;
			solve({ i, j }, 1, board[i][j]);
			vis[i][j] = 0;
		}
	}

	cout << ans;

	return 0;
}