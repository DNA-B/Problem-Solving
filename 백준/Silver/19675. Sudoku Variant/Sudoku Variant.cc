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
int res = 0;
int board[3][3];
vector<pair<int, int>> zero;
//=========================//

bool check(int x, int y) {
	for (int i = 0; i < 3; i++) {
		if ((i != x && board[x][y] == board[i][y]) || (i != y && board[x][y] == board[x][i]))
			return false;
	}
	return true;
}

void solve(int cur) {
	if (cur == zero.size()) {
		res++;
		return;
	}

	auto [nx, ny] = zero[cur];
	for (int i = 1; i <= 9; i++) {
		board[nx][ny] = i;
		if (check(nx, ny)) solve(cur + 1);
	}

	board[nx][ny] = 0;
	return;
}


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> board[i][j];

			if (board[i][j] == 0)
				zero.push_back({ i, j });
		}
	}

	solve(0);
	cout << res;
}