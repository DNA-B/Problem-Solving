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
int N, M, K, cnt = 1;
int board[1005][1005];
pair<int, int> dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> M >> N >> K;

	int x = 1, y = 1, cur = 0;
	while (cnt <= N * M) {
		board[x][y] = cnt++;

		int nx = x + dir[cur].X;
		int ny = y + dir[cur].Y;

		if (nx < 1 || nx > N || ny < 1 || ny > M)
			cur = (cur + 1) % 4;
		else if (board[nx][ny] != 0)
			cur = (cur + 1) % 4;

		x = x + dir[cur].X;
		y = y + dir[cur].Y;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == K) {
				cout << j << ' ' << i;
				exit(0);
			}
		}
	}

	cout << 0;
}