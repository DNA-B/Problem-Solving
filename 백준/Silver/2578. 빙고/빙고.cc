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
int cnt = 0;
int board[20][20], vis[20][20];
pair<int, int> xy[30];
//=========================//

bool check() {
	int bingo = 0, diagR = 0, diagL = 0;

	for (int i = 0; i < 5; i++) {
		int row = 0, col = 0;

		for (int j = 0; j < 5; j++) {
			row += vis[i][j];
			col += vis[j][i];
		}

		diagR += vis[i][i];
		diagL += vis[i][4 - i];

		if (col == 5) bingo++;
		if (row == 5) bingo++;
	}

	if (diagR == 5) bingo++;
	if (diagL == 5) bingo++;

	return bingo >= 3;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
			xy[board[i][j]] = { i, j };
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int call, j = 0; j < 5; j++) {
			cin >> call;

			auto [x, y] = xy[call];
			vis[x][y] = 1;
			cnt++;
			if (check()) {
				cout << cnt;
				exit(0);
			}
		}
	}
}