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
int T, N, M;
int board[105][105], zboard[105][105][5];
//=========================//

pair<int, int> zip_proc(int x, int y) {
	int mn = INF, mn_abs = INF, idx = -1;
	for (int k = 0; k < 5; k++) {
		int v = board[x][y] - zboard[x][y][k];
		if (abs(v) < mn_abs) {
			mn_abs = abs(v);
			mn = v;
			idx = k;
		}
	}

	return { idx, mn };
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[i][j];

				int A = (j - 1 < 0 ? 0 : board[i][j - 1]);
				int B = (i - 1 < 0 ? 0 : board[i - 1][j]);
				int C = (i - 1 < 0 || j - 1 < 0 ? 0 : board[i - 1][j - 1]);

				zboard[i][j][0] = 0;
				zboard[i][j][1] = A;
				zboard[i][j][2] = B;
				zboard[i][j][3] = (A + B) / 2;
				zboard[i][j][4] = A + B - C;

				auto [idx, mn] = zip_proc(i, j);
				cout << idx << ' ' << mn << ' ';
			}
			cout << '\n';
		}
	}
}