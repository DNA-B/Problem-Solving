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
int N, M, cnt = 0, mn = INT_MAX;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int vis[55][55];
char board[55][55];
vector<pair<int, int>> regions[5];
//=========================//

void bfs(int i, int j) {
	queue<pair<int, int>> q;

	vis[i][j] = cnt;
	regions[cnt].push_back({ i, j });
	q.push({ i, j });
	while (!q.empty()) {
		auto& [x, y] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (vis[nx][ny] || board[nx][ny] == '.')
				continue;

			vis[nx][ny] = cnt;
			regions[cnt].push_back({ nx, ny });
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

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'X' && !vis[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	for (auto& [x1, y1] : regions[1]) {
		for (auto& [x2, y2] : regions[2]) {
			int dist = abs(x1 - x2) + abs(y1 - y2) - 1;
			mn = min(mn, dist);
		}
	}

	cout << mn;
}