#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
// #define X first
// #define Y second
//=========================//

//======= VARIABLEs =======//
int N, K, S, X, Y;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0 ,1, -1 };
int board[205][205], vis[205][205];
vector<pair<int, int>> virus[1005];
queue<pair<int, int>> q;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			virus[board[i][j]].push_back({ i, j });
		}
	}

	memset(vis, -1, sizeof(vis));

	for (int i = 1; i <= K; i++) { // 1 ~ K까지 하나씩만 존재한다는 보장 X
		for (auto [x, y] : virus[i]) {
			vis[x][y] = 0;
			q.push({ x, y });
		}
	}

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;
			if (vis[nx][ny] != -1 || board[nx][ny])
				continue;

			vis[nx][ny] = vis[x][y] + 1;
			board[nx][ny] = board[x][y];
			q.push({ nx, ny });
		}
	}

	cin >> S >> X >> Y;

	if (vis[X][Y] == -1 || vis[X][Y] > S)
		cout << 0;
	else
		cout << board[X][Y];
}