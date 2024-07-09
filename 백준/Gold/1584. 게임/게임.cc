#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 501
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, X1, X2, Y1, Y2;
int d[BOUND][BOUND];
int board[BOUND][BOUND];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0,-1, 1 };
priority_queue<tuple<int, int, int>,
	vector<tuple<int, int, int>>,
	greater<tuple<int, int, int>>> pq;
/***********************/

void dijk() {
	while (!pq.empty()) {
		auto [x, y, cur_d] = pq.top();
		pq.pop();

		if (d[x][y] != cur_d)
			continue;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx > 500 || ny < 0 || ny > 500)
				continue;
			if (board[nx][ny] == 2) // 죽음의 구역
				continue;
			if (d[nx][ny] <= cur_d + board[nx][ny])
				continue;

			d[nx][ny] = cur_d + board[nx][ny];
			pq.push({ nx, ny, d[nx][ny] });
		}
	}
}


int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i <= 500; i++)
		for (int j = 0; j <= 500; j++)
			d[i][j] = INF;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> X1 >> Y1 >> X2 >> Y2;

		for (int j = min(X1, X2); j <= max(X1, X2); j++)
			for (int k = min(Y1, Y2); k <= max(Y1, Y2); k++)
				board[j][k] = 1;
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> X1 >> Y1 >> X2 >> Y2;

		for (int j = min(X1, X2); j <= max(X1, X2); j++)
			for (int k = min(Y1, Y2); k <= max(Y1, Y2); k++)
				board[j][k] = 2;
	}

	d[0][0] = 0;
	pq.push({ 0, 0, 0 });
	dijk();
	cout << (d[500][500] == INF ? -1 : d[500][500]);

	return 0;
}