#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
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
const string YOKOHAMA = "YOKOHAMA";
int N, M, res = 0;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char board[15][15];
//=========================//

int bfs(int x, int y) {
	int cnt = 0;
	queue<tuple<int, int, int>> q;

	q.push({ x, y, 0 });
	while (!q.empty()) {
		auto [x, y, idx] = q.front(); q.pop();

		if (idx == 7) { // YOKOHAMA SIZE - 1
			cnt++;
			continue;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (board[nx][ny] != YOKOHAMA[idx + 1])
				continue;

			q.push({ nx, ny, idx + 1 });
		}
	}

	return cnt;
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
			if (board[i][j] == 'Y')
				res += bfs(i, j);
		}
	}

	cout << res;
}