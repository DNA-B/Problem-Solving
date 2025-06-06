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
int N, M, cnt = 0, rep = 0;
int board[105][105], vis[105][105];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
set<pair<int, int>> melted;
//=========================//

void bfs() {
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (vis[nx][ny])
				continue;
			if (board[nx][ny]) {
				melted.insert({ nx, ny });
				continue;
			}

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

void solve() {
	melted.clear();
	q.push({ 0, 0 });
	vis[0][0] = 1;
	bfs();

	for (auto [x, y] : melted)
		board[x][y] = 0;
}

int get_cheese() {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			tmp += board[i][j];
	}

	return tmp;
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

	while (true) {
		int tmp = get_cheese();
		if (!tmp) break;

		cnt = tmp;
		rep++;
		memset(vis, 0, sizeof(vis));
		solve();
	}

	cout << rep << '\n' << cnt;
}