#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, Hx, Hy, Ex, Ey;
int board[1005][1005];
int vis[1005][1005][2]; // x, y, 벽 부쉈는지 여부
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1 ,1 };
/***********************/

int bfs() {
	queue<tuple<int, int, bool, int>> q; // {x, y, 벽 부순 여부, 거리}
	q.push({ Hx, Hy, 0, 0 });

	while (!q.empty()) {
		auto [x, y, is_crash, cnt] = q.front();
		q.pop();

		if (x == Ex && y == Ey)
			return cnt;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 1 || nx > N || ny < 1 || ny > M)
				continue;
			if (vis[nx][ny][is_crash])
				continue;

			if (board[nx][ny] == 1 && is_crash == false) {
				vis[nx][ny][!is_crash] = 1;
				q.push({ nx, ny, !is_crash, cnt + 1 });
			}
			else if (board[nx][ny] == 0) {
				vis[nx][ny][is_crash] = 1;
				q.push({ nx, ny, is_crash, cnt + 1 });
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> Hx >> Hy >> Ex >> Ey;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
	}

	cout << bfs();
	return 0;
}