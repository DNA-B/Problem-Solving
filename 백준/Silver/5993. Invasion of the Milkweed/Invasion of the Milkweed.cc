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
int N, M, Mx, My, mx = 0;
char board[105][105];
int vis[105][105];
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
queue<pair<int, int>> q;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> M >> N >> Mx >> My; // X가 N이고 Y가 M임 해당 문제는 Y X로 입력 들어오는 중

	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];
	}

	vis[My][Mx] = 0; // 해당 문제는 My가 x고 Mx가 y임
	q.push({ My, Mx });
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 1 || nx > N || ny < 1 || ny > M)
				continue;
			if (board[nx][ny] == '*' || vis[nx][ny])
				continue;

			vis[nx][ny] = vis[x][y] + 1;
			mx = max(mx, vis[nx][ny]);
			q.push({ nx, ny });
		}
	}

	cout << mx;
}