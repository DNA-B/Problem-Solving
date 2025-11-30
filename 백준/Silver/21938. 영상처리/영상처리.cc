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
int N, M, T, res = 0;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int board[1005][1005], vis[1005][1005];
queue<pair<int, int>> q;
//=========================//

void bfs(int i, int j) {
	q.push({ i, j });
	vis[i][j] = 1;

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (vis[nx][ny] || !board[nx][ny])
				continue;

			q.push({ nx, ny });
			vis[nx][ny] = 1;
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
		for (int j = 0; j < M; j++) {
			int total = 0, x;
			for (int k = 0; k < 3; k++) {
				cin >> x;
				total += x;
			}
			board[i][j] = total / 3;
		}
	}

	cin >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			board[i][j] = (board[i][j] >= T ? 255 : 0);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vis[i][j] && board[i][j]) {
				bfs(i, j);
				res++;
			}
		}
	}

	cout << res;
}