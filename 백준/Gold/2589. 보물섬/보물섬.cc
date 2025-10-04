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
int R, C, res = -1;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char board[55][55];
//=========================//

int bfs(int x, int y, char land) {
	int cnt = 0;
	int vis[55][55] = { 0, };
	queue<pair<int, int>> q;

	memset(vis, -1, sizeof(vis));
	q.push({ x, y });
	vis[x][y] = 0;

	while (!q.empty()) {
		auto [cur_x, cur_y] = q.front();
		q.pop();
		cnt = max(cnt, vis[cur_x][cur_y]);

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur_x + dx[dir];
			int ny = cur_y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (board[nx][ny] != 'L' || vis[nx][ny] != -1)
				continue;

			vis[nx][ny] = vis[cur_x][cur_y] + 1;
			q.push({ nx, ny });
		}
	}

	return cnt;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'L')
				res = max(res, bfs(i, j, board[i][j]));
		}
	}

	cout << res;
}