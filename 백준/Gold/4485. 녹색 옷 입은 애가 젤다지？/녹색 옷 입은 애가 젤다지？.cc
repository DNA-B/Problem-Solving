#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 126
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, problem = 1;
int board[BOUND][BOUND];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	while (true) {
		int d[BOUND][BOUND];
		priority_queue <tuple<int, int, int>,
			vector<tuple<int, int, int>>,
			greater<tuple<int, int, int>>> pq;

		fill(&d[0][0], &d[BOUND - 1][BOUND], INT_MAX);

		cin >> N;

		if (N == 0) // 입력 종료
			break;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> board[i][j];

		d[0][0] = board[0][0];
		pq.push({ d[0][0], 0, 0 });

		while (!pq.empty()) {
			int cur_cost, cur_x, cur_y;

			tie(cur_cost, cur_x, cur_y) = pq.top();
			pq.pop();

			if (d[cur_x][cur_y] != cur_cost)
				continue;

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur_x + dx[dir];
				int ny = cur_y + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;
				if (d[nx][ny] <= cur_cost + board[nx][ny])
					continue;

				d[nx][ny] = cur_cost + board[nx][ny];
				pq.push({ d[nx][ny], nx, ny });
			}
		}

		cout << "Problem " << problem++ << ": " << d[N - 1][N - 1] << "\n";
	}

	return 0;
}