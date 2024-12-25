#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N, res = INT_MAX;
char board[55][55];
int vis[55][55];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
//=========================//

void bfs() {
	vis[0][0] = 0;
	q.push({ 0, 0 });
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (board[nx][ny] == '0' && vis[x][y] + 1 < vis[nx][ny]) {
				vis[nx][ny] = vis[x][y] + 1;
				q.push({ nx, ny });
			}
			else if (board[nx][ny] == '1' && vis[x][y] < vis[nx][ny]) {
				vis[nx][ny] = vis[x][y];
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		fill(vis[i], vis[i] + N, INT_MAX);
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	bfs();
	cout << vis[N - 1][N - 1];
}