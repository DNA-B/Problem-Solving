#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M, B;
int board[501][501];
int ans_time = INT_MAX, ans_height = INT_MIN, max_height = INT_MIN;

void solve(int cur_height) {
	int cur_time = 0;
	int cur_block = B;
	bool is_impossible = false;

	for (int i = 0; i < N; i++) { // cur_gheight보다 큰 땅의 블럭을 인벤토리에 축적
		for (int j = 0; j < M; j++) {
			int sub_height = abs(board[i][j] - cur_height);

			if (board[i][j] > cur_height) {
				cur_block += sub_height;
				cur_time += 2 * sub_height;
			}
		}
	}

	for (int i = 0; i < N; i++) { // cur_gheight보다 적은 땅의 블럭을 인벤토리에서 꺼내서 쌓기
		for (int j = 0; j < M; j++) {
			int sub_height = abs(board[i][j] - cur_height);

			if (board[i][j] < cur_height) {
				if (cur_block < sub_height) // 인벤토리에 sub_height만큼의 블럭이 없음
					return;

				cur_block -= sub_height;
				cur_time += sub_height;
			}
		}
	}

	if (ans_time > cur_time) {
		ans_time = cur_time;
		ans_height = cur_height;
	}

	if (ans_time == cur_time) // 같은 시간일 경우 최대 높이가 더 큰 경우를 선택
		ans_height = max(ans_height, cur_height);

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			max_height = max(max_height, board[i][j]);
		}
	}

	while (max_height >= 0) {
		solve(max_height);
		max_height--;
	}

	cout << ans_time << " " << ans_height;

	return 0;
}