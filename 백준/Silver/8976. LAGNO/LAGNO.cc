#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 50000
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
char board[8][8];
int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int res = 0;
/***********************/

int solve(int x, int y) {
	int total = 0;

	for (int dir = 0; dir < 8; dir++) {
		for (int cnt = 0, i = 1; i <= 8; i++) {
			int nx = x + (dx[dir] * i);
			int ny = y + (dy[dir] * i);

			if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
				break;
			else if (board[nx][ny] == '.')
				break;

			if (board[nx][ny] == 'B') {
				total += cnt;
				break;
			}

			cnt++;
		}
	}

	return total;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> board[i][j];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 'B' || board[i][j] == 'W')
				continue;
			else
				res = max(res, solve(i, j));
		}
	}

	cout << res;

	return 0;
}