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
int W, H;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (cin >> W >> H) {
		if (W == 0 && H == 0)
			exit(0);

		vector<vector<char>> board(H + 5, vector<char>(W + 5));
		vector<vector<bool>> vis(H + 5, vector<bool>(W + 5, false));
		string row;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> board[i][j];
				if (board[i][j] == 'S') {
					vis[i][j] = true;
					q.push({ i, j });
				}
			}
		}

		while (!q.empty()) {
			auto [x, y] = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || nx >= H || ny < 0 || ny >= W)
					continue;
				if (vis[nx][ny] || board[nx][ny] == '.')
					continue;

				board[nx][ny] = 'S';
				vis[nx][ny] = true;
				q.push({ nx, ny });
			}
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
				cout << board[i][j];
			cout << '\n';
		}
	}
}