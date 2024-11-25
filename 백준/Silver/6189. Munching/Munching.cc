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
int R, C;
char board[105][105];
int vis[105][150];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		fill(vis[i], vis[i] + C, -1);

		for (int j = 0; j < C; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'B') {
				vis[i][j] = 0;
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		if (board[x][y] == 'C') {
			cout << vis[x][y];
			exit(0);
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (vis[nx][ny] != -1 || board[nx][ny] == '*')
				continue;

			vis[nx][ny] = vis[x][y] + 1;
			q.push({ nx, ny });
		}
	}
}