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
vector<string> board;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// cout.tie(NULL);
	// freopen("input.txt", "r", stdin);

	while (cin >> R >> C) {
		if (R == 0 && C == 0)
			break;

		board.resize(R);
		for (string& row : board)
			cin >> row;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (board[i][j] == '*')
					continue;

				board[i][j] = '0';
				for (int dir = 0; dir < 8; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 0 || nx >= R || ny < 0 || ny >= C)
						continue;
					if (board[nx][ny] == '*')
						board[i][j]++;
				}
			}
			cout << board[i] << "\n";
		}
	}

	return 0;
}