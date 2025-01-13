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
int N, M, cnt = 0, ice = 0;
int board[305][305], vis[305][305];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
//=========================//

bool bfs() {
	int touch = 0, melt = 0;
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		touch++;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (vis[nx][ny])
				continue;
			if (!board[nx][ny]) {
				board[x][y] = max(0, board[x][y] - 1);
				continue;
			}

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}

		if (!board[x][y])
			melt++;
	}

	if (touch == ice) {
		ice -= melt;
		return true;
	}

	return false;
}

bool solve() {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] && !vis[i][j]) {
				q.push({ i, j });
				vis[i][j] = 1;
				return bfs();
			}
		}
	}

	cnt = 0; // 모든 빙산 녹았다면 0 출력
	return false;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j]) ice++;
		}
	}

	while (solve()) {
		memset(vis, 0, sizeof(vis));
		cnt++;
	}

	cout << cnt;
}