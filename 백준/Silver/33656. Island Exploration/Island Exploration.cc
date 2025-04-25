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
int R, C, cnt = 0;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int vis[105][105];
char board[105][105];
queue<pair<int, int>> q;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'S') {
				q.push({ i, j });
				vis[i][j] = 1;
				cnt++;
			}
		}
	}

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (vis[nx][ny] || board[nx][ny] != '#')
				continue;

			q.push({ nx, ny });
			vis[nx][ny] = 1;
			cnt++;
		}
	}

	cout << cnt;
}