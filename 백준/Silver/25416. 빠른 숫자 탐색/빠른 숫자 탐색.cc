#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int R, C, hx, hy;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int vis[10][10], board[10][10];
queue<pair<int, int>> q;
//=========================//

void bfs() {
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
				continue;
			if (vis[nx][ny] > -1 || board[nx][ny] == -1)
				continue;

			vis[nx][ny] = vis[x][y] + 1;
			q.push({ nx, ny });
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int i = 0; i < 5; i++) {
		fill(vis[i], vis[i] + 5, -1);
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) hx = i, hy = j;
		}
	}

	cin >> R >> C;

	vis[R][C] = 0;
	q.push({ R, C });
	bfs();

	cout << vis[hx][hy];
}