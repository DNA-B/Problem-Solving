#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 105
#define MOD 1'000'000'007
#define PI 3.14159265358979323846
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
int dx[] = { 0, 1 };
int dy[] = { 1, 0 };
int vis[BOUND][BOUND];
char board[BOUND][BOUND];
queue<pair<int, int>> q;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	vis[0][0] = 1;
	q.push({ 0, 0 });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 2; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (vis[nx][ny] != 0)
				continue;
			if (board[nx][ny] == 'x')
				continue;

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

	cout << (vis[N - 1][N - 1] ? "Yes" : "No");

	return 0;
}