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
int R, S;
char board[55][55];
bool vis[55][55][55][55] = { 0, };
int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
//=========================//

int check(int x, int y) {
	memset(vis, 0, sizeof(vis));

	if (x != -1 && y != -1)
		board[x][y] = 'o';

	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			if (board[i][j] == 'o') {
				for (int dir = 0; dir < 8; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 0 || nx >= R || ny < 0 || ny >= S)
						continue;
					if (board[nx][ny] == '.')
						continue;
					if (vis[nx][ny][i][j] != 0)
						continue;

					vis[i][j][nx][ny] = 1;
					vis[nx][ny][i][j] = 1;
					cnt++;
				}
			}
		}
	}

	if (x != -1 && y != -1)
		board[x][y] = '.';

	return cnt;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> R >> S;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++)
			cin >> board[i][j];
	}

	int mx = check(-1, -1);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < S; j++) {
			if (board[i][j] == '.') {
				mx = max(mx, check(i, j));
			}
		}
	}

	cout << mx;
}