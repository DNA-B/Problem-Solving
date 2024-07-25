#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int R, C;
char board[101][101];
char res[101][101];
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
/***********************/

char get_mine(int x, int y) {
	int cnt = 0;
	for (int dir = 0; dir < 8; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			continue;
		if (board[nx][ny] == '*')
			cnt++;
	}
	return cnt + '0';
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (1) {
		cin >> R >> C;

		if (R == 0 && C == 0)
			break;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				cin >> board[i][j];
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				res[i][j] = (board[i][j] == '*' ? '*' : get_mine(i, j));
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)
				cout << res[i][j];
			cout << "\n";
		}
	}

	return 0;
}