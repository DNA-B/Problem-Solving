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
int N, M, mx = -1;
char board[1005][105];
int vis[1005][105];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
//=========================//

int bfs() {
	int cnt = 0;
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		cnt++;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (vis[nx][ny] || board[nx][ny] == '.')
				continue;

			vis[nx][ny] = vis[x][y] + 1;
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

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vis[i][j] && board[i][j] == '*') {
				vis[i][j] = 1;
				q.push({ i, j });
				mx = max(mx, bfs());
			}
		}
	}

	cout << mx;
}