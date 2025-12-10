#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
int N;
char NG;
char board[5][5];
//=========================//

bool check(int x, int y) {
	if (board[x][0] == NG && board[x][1] == NG && board[x][2] == NG)
		return true;
	else if (board[0][y] == NG && board[1][y] == NG && board[2][y] == NG)
		return true;

	// (1, 1)은 둘 다 체크해야되니까 if-else if ㄴㄴ
	if (x == y) { // 좌상 -> 우하
		if (board[0][0] == NG && board[1][1] == NG && board[2][2] == NG)
			return true;
	}

	if (x + y == 2) { // 우상 -> 좌하
		if (board[0][2] == NG && board[1][1] == NG && board[2][0] == NG)
			return true;
	}

	return false;
}

void print_board() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << board[i][j];
		cout << '\n';
	}
}

void solve() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '-') {
				board[i][j] = NG;
				if (check(i, j)) {
					print_board();
					return;
				}
				board[i][j] = '-';
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int tc = 1; tc <= N; tc++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cin >> board[i][j];
		}

		cin >> NG;
		cout << "Case " << tc << ":\n";
		solve();
	}
}