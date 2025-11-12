#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
int R, C;
pair<int, int> B;
int vis1[55][55], vis2[55][55];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char board[55][55];
queue<pair<int, int>> q1, q2;
//=========================//

void bfs1() {
	while (!q1.empty()) {
		auto [x, y] = q1.front();
		q1.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (board[nx][ny] == 'D' || board[nx][ny] == 'X')
				continue;
			if (vis1[nx][ny] != -1)
				continue;

			q1.push({ nx, ny });
			vis1[nx][ny] = vis1[x][y] + 1;
		}
	}
}

void bfs2() {
	while (!q2.empty()) {
		auto [x, y] = q2.front();
		q2.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (board[nx][ny] == '*' || board[nx][ny] == 'X')
				continue;
			if (vis2[nx][ny] != -1)
				continue;
			if (vis1[nx][ny] != -1 && vis1[nx][ny] <= vis2[x][y] + 1) // 물이 차 있거나 찰 예정이면 continue
				continue;
			if (board[nx][ny] == 'D') { // 비버 집 도착
				cout << vis2[x][y] + 1;
				exit(0);
			}

			q2.push({ nx, ny });
			vis2[nx][ny] = vis2[x][y] + 1;
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	memset(vis1, -1, sizeof(vis1));
	memset(vis2, -1, sizeof(vis2));

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == '*') {
				vis1[i][j] = 0;
				q1.push({ i, j });
			} else if (board[i][j] == 'S') {
				vis2[i][j] = 0;
				q2.push({ i, j });
			}
		}
	}

	bfs1();
	bfs2();
	cout << "KAKTUS";
}