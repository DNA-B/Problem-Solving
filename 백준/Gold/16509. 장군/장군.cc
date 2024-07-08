#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 50001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int r1, r2, c1, c2;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int vis[10][9];
queue<pair<int, int>> q;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> r1 >> c1 >> r2 >> c2;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 9; j++)
			vis[i][j] = -1;

	vis[r1][c1] = 0;
	q.push({ r1, c1 });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			for (int diag = 0; diag < 2; diag++) {
				int tmp_x = nx, tmp_y = ny;

				switch (diag) {
					case 0:
						tmp_x = (dx[dir] == 0 ? tmp_x - 1 : tmp_x + dx[dir]);
						tmp_y = (dy[dir] == 0 ? tmp_y - 1 : tmp_y + dy[dir]);

						if (tmp_x == r2 && tmp_y == c2) // 움직이는 중간에 기물이 있으면 이동 불가
							continue;

						tmp_x = (dx[dir] == 0 ? tmp_x - 1 : tmp_x + dx[dir]);
						tmp_y = (dy[dir] == 0 ? tmp_y - 1 : tmp_y + dy[dir]);
						break;
					case 1:
						tmp_x = (dx[dir] == 0 ? tmp_x + 1 : tmp_x + dx[dir]);
						tmp_y = (dy[dir] == 0 ? tmp_y + 1 : tmp_y + dy[dir]);

						if (tmp_x == r2 && tmp_y == c2) // 움직이는 중간에 기물이 있으면 이동 불가
							continue;

						tmp_x = (dx[dir] == 0 ? tmp_x + 1 : tmp_x + dx[dir]);
						tmp_y = (dy[dir] == 0 ? tmp_y + 1 : tmp_y + dy[dir]);
						break;
				}

				if (tmp_x < 0 || tmp_x >= 10 || tmp_y < 0 || tmp_y >= 9)
					continue;
				if (vis[tmp_x][tmp_y] != -1)
					continue;

				vis[tmp_x][tmp_y] = vis[cur.X][cur.Y] + 1;
				q.push({ tmp_x, tmp_y });
			}
		}
	}

	cout << vis[r2][c2];
	return 0;
}