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
int N, res = 0;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int vis[25][25], board[25][25];
int likes[405][405];
//=========================//

pair<int, int> solve(int cur_stu) {
	vector<pair<int, int>> cand;
	int adj[25][25] = { 0, };
	int cur_like[25][25] = { 0, };
	int mx_like = 0;

	// 1번 조건
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)
						continue;
					if (!board[nx][ny])
						adj[i][j]++;
					if (likes[cur_stu][board[nx][ny]])
						cur_like[i][j]++;
				}

				mx_like = max(mx_like, cur_like[i][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) { // 1번 조건
		for (int j = 0; j < N; j++) {
			if (!vis[i][j] && cur_like[i][j] == mx_like)
				cand.push_back({ i, j });
		}
	}

	sort(cand.begin(), cand.end(), [&](pair<int, int> a, pair<int, int> b) {
		auto [x1, y1] = a;
		auto [x2, y2] = b;

		if (adj[x1][y1] == adj[x2][y2]) { // 3번 조건
			if (x1 == x2)
				return y1 < y2;
			else
				return x1 < x2;
		}

		return adj[x1][y1] > adj[x2][y2];
		}); // 2번 조건

	return cand.front();
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	queue<int> order;
	for (int u, i = 0; i < N * N; i++) {
		cin >> u;
		order.push(u);
		for (int v, j = 0; j < 4; j++) {
			cin >> v;
			likes[u][v] = 1;
		}
	}

	while (!order.empty()) {
		int cur = order.front(); order.pop();
		auto [x, y] = solve(cur);
		board[x][y] = cur, vis[x][y] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;
				if (likes[board[i][j]][board[nx][ny]])
					cnt++;
			}

			res += (cnt == 0 ? 0 : pow(10, cnt - 1));
		}
	}

	cout << res;
}