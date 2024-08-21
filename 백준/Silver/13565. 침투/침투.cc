#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int M, N;
string board[1005];
int vis[1005][1005];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
/***********************/

void bfs() {
	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N)
				continue;
			if (vis[nx][ny] || board[nx][ny] == '1')
				continue;

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		cin >> board[i];

		if (i == 0) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == '0') {
					vis[i][j] = 1;
					q.push({ i, j });
				}
			}
		}
	}

	bfs();

	for (int i = 0; i < N; i++) {
		if (board[M - 1][i] != '1' && vis[M - 1][i]) {
			cout << "YES";
			exit(0);
		}
	}

	cout << "NO";
	return 0;
}