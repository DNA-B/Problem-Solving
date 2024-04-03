#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;
int cnt_row = 0, cnt_col = 0;
char board[51][51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int row = 0; row < N; row++) {
		bool is_guard = false;

		for (int col = 0; col < M; col++) {
			if (board[row][col] == 'X')
				is_guard = true;
		}

		if (!is_guard)
			cnt_row++;
	}

	for (int col = 0; col < M; col++) {
		bool is_guard = false;

		for (int row = 0; row < N; row++) {
			if (board[row][col] == 'X')
				is_guard = true;
		}

		if (!is_guard)
			cnt_col++;
	}

	cout << max(cnt_row, cnt_col);

	return 0;
}