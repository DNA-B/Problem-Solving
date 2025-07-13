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
char board[10][10];
//=========================//

bool check(int x, int y) {
	for (int i = 0; i < 8; i++) {
		if (board[x][i] == 'R')
			return false;
		if (board[i][y] == 'R')
			return false;
	}

	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++)
			cin >> board[r][c];
	}

	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (board[r][c] == '.' && check(r, c))
				cnt++;
		}
	}

	cout << cnt;
}