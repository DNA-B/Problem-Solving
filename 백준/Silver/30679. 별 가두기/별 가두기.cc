#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 101
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int board[BOUND][BOUND];
vector<int> res;
/***********************/

bool solve(int x, int y) {
	int dir = 0, cnt = 1;

	while (1) {
		x += board[x][y] * dx[dir];
		y += board[x][y] * dy[dir];

		if (x < 1 || x > N || y < 1 || y > M) // 가두기 실패
			return false;
		if (cnt > 2* N * M)
			return true;

		cnt++;
		dir = (dir + 1) % 4;
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	for (int i = 1; i <= N; i++) {
		if (solve(i, 1))
			res.push_back(i);
	}

	cout << res.size() << (res.empty() ? "" : "\n");
	for (int row : res)
		cout << row << " ";

	return 0;
}