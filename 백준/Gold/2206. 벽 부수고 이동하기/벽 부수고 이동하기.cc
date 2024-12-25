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
string board[1000];
int vis[1000][1000][2]; // x, y, 벽 부쉈는지 여부
int n, m;
int dx[4] = { -1, 1, 0, 0 }; // 상하좌우
int dy[4] = { 0, 0, -1 ,1 };
/***********************/

int bfs() {
	queue<tuple<int, int, bool>> q;
	q.push({ 0, 0, false }); // {x,y}, {벽 부순 여부, 거리}
	vis[0][0][0] = 1;

	while (!q.empty()) {
		auto [x, y, is_crash] = q.front();
		q.pop();

		if (x == n - 1 && y == m - 1) // 도착
			return vis[x][y][is_crash];

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir]; // 방향 설정
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny >= m || ny < 0)
				continue; // 범위 밖일 경우
			if (vis[nx][ny][is_crash])
				continue;

			if (board[nx][ny] == '1' && is_crash == 0) { // 벽 있는데 안 부쉈으면
				vis[nx][ny][!is_crash] = vis[x][y][is_crash] + 1;
				q.push({ nx, ny, !is_crash });
			}
			else if (board[nx][ny] == '0') { // 벽 없으면
				vis[nx][ny][is_crash] = vis[x][y][is_crash] + 1;
				q.push({ nx, ny, is_crash });
			}
		}
	}

	return -1; // 도착 못함
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	cout << bfs();

	return 0;
}