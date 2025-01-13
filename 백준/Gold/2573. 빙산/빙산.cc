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
int N, M, cnt = 0;
int board[305][305], vis[305][305];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
//=========================//

bool is_discrete() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (board[i][j] && !vis[i][j])
				return true;
	}
	return false;
}

void melt(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		if (vis[nx][ny] || board[nx][ny] != 0)
			continue;

		board[x][y] = max(0, board[x][y] - 1);
	}
}

void bfs() {
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		melt(x, y);

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (vis[nx][ny] || !board[nx][ny])
				continue;

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

bool solve() {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] && !vis[i][j]) {
				q.push({ i, j });
				vis[i][j] = 1;
				bfs();
				return true;
			}
		}
	}

	cnt = 0;
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
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}

	while (solve()) {
		if (is_discrete()) break;
		else cnt++;
		memset(vis, 0, sizeof(vis));
	}

	cout << cnt;
}