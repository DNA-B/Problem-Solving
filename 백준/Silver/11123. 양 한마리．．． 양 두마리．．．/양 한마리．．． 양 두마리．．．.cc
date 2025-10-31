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
int T, H, W;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
char board[105][105];
queue<pair<int, int>> q;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		int cnt = 0;
		int vis[105][105] = { 0, };
		vector<pair<int, int>> sheeps;

		cin >> H >> W;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> board[i][j];
				if (board[i][j] == '#')
					sheeps.push_back({ i, j });
			}
		}

		for (auto [x, y] : sheeps) {
			if (!vis[x][y]) {
				cnt++;
				vis[x][y] = 1;
				q.push({ x, y });

				while (!q.empty()) {
					auto [cur_x, cur_y] = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur_x + dx[dir];
						int ny = cur_y + dy[dir];

						if (nx < 0 || nx >= H || ny < 0 || ny >= W)
							continue;
						if (board[nx][ny] == '.' || vis[nx][ny])
							continue;

						vis[nx][ny] = 1;
						q.push({ nx, ny });
					}
				}
			}
		}

		cout << cnt << '\n';
	}
}