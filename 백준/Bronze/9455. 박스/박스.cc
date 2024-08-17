#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, N, M;
int board[105][105];
/***********************/

int change_box(int x, int y) {
	int dist = 0;
	while (board[x + 1][y] != 1) {
		if (x + 1 >= M) break;
		swap(board[x][y], board[x + 1][y]);
		dist++; x++;
	}
	return dist;
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		int dist = 0;
		cin >> M >> N;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++)
				cin >> board[i][j];
		}

		for (int i = 0; i < N; i++) {
			for (int j = M - 1; j >= 0; j--) {
				if (board[j][i] == 1)
					dist += change_box(j, i);
			}
		}
		cout << dist << '\n';
	}

	return 0;
}