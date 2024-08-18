#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
int res = 0, cnt = 0, land_cnt = 0;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int board[15][15];
int vis[15][15];
queue<pair<int, int>> q, land;
vector<int> p(105, -1);
vector<tuple<int, int, int>> edge;
/***********************/

int uf_find(int x) {
	if (p[x] < 0)
		return x;
	return p[x] = uf_find(p[x]);
}

bool uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);

	if (a == b) return false;
	if (p[a] == p[b]) p[a]--;

	if (p[a] < p[b]) p[a] = b;
	else p[b] = a;

	return true;
}

void bfs(pair<int, int> xy) {
	land_cnt++;
	vis[xy.X][xy.Y] = land_cnt;
	q.push(xy);

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (vis[nx][ny] || board[nx][ny] == 0)
				continue;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			vis[nx][ny] = land_cnt;
			q.push({ nx, ny });
			land.push({ nx,ny });
		}
	}
}

void make_bridge() {
	while (!land.empty()) {
		auto [x, y] = land.front(); land.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int dist = 0;

			while (1) {
				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					break;
				if (vis[nx][ny] == vis[x][y]) // 같은 섬
					break;
				if (vis[nx][ny] != 0 && (vis[nx][ny] != vis[x][y])) {
					if (dist >= 2) edge.push_back({ dist, vis[x][y], vis[nx][ny] });
					break;
				}

				dist++;
				nx += dx[dir];
				ny += dy[dir];
			}
		}
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) land.push({ i, j });
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] != 0 && !vis[i][j])
				bfs({ i, j });
		}
	}

	make_bridge();
	sort(edge.begin(), edge.end());

	cnt = 0;
	for (auto [cost, x, y] : edge) {
		if (cnt == land_cnt - 1)
			break;
		if (!uf_union(x, y))
			continue;
		res += cost;
		cnt++;
	}

	cout << (cnt != land_cnt - 1 ? -1 : res);
	return 0;
}