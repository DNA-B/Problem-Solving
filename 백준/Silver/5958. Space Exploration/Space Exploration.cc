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
int N, cnt = 0;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int vis[1005][1005];
char board[1005][1005];
//=========================//

void bfs(int x, int y) {
	queue<pair<int, int>> q;

	vis[x][y] = 1;
	q.push({ x, y });
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (vis[nx][ny] || board[nx][ny] == '.')
				continue;

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '*' && !vis[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	cout << cnt;
}