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
int N, M, res = 0, vis = 0;
int x = 0, y = 0, dir = 0;
int board[BOUND][BOUND];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
/***********************/


int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> M >> N;

	while (1) {
		board[x][y] = 1;
		vis++;

		if (vis == N * M)
			break;

		if (x + dx[dir] < 0 || x + dx[dir] >= M || y + dy[dir] < 0 || y + dy[dir] >= N) {
			dir = (dir + 1) % 4; // 다음 좌표가 경계를 벗어나는 경우 방향 전환
			res++;
		}
		if (board[x + dx[dir]][y + dy[dir]] != 0) {// 다음 좌표에 이미 값이 있는 경우 방향 전환
			dir = (dir + 1) % 4;
			res++;
		}

		x += dx[dir];
		y += dy[dir];
	}

	cout << res;
	return 0;
}