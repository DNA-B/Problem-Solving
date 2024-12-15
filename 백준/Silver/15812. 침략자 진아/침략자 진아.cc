#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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
int N, M, mn = INT_MAX;
char board[25][25];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
vector<pair<int, int>> house;
//=========================//

int bfs(int x1, int y1, int x2, int y2) {
	int vis[25][25];
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
		fill(vis[i], vis[i] + M, -1);

	vis[x1][y1] = vis[x2][y2] = 0;
	q.push({ x1, y1 });
	q.push({ x2, y2 });

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (vis[nx][ny] != -1)
				continue;

			vis[nx][ny] = vis[x][y] + 1;
			q.push({ nx, ny });
		}
	}

	int mx = -1;
	for (auto [x, y] : house)
		mx = max(mx, vis[x][y]);

	return mx;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == '1')
				house.push_back({ i, j });
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == '1')
				continue;
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < M; l++) {
					if (board[k][l] == '1')
						continue;
					if (k == i && l == j)
						continue;
					mn = min(mn, bfs(i, j, k, l));
				}
			}
		}
	}

	cout << mn;
}
