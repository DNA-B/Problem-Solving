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
int T, H, W, res = 0;
bool has_keys[26];
int vis[105][105];
char board[105][105];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
//=========================//

bool bfs() {
	q.push({ 0, 0 });
	vis[0][0] = 1;

	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx > H + 1 || ny < 0 || ny > W + 1)
				continue;
			if (board[nx][ny] == '*' || vis[nx][ny])
				continue;
			if ('A' <= board[nx][ny] && board[nx][ny] <= 'Z') {
				if (!has_keys[board[nx][ny] - 'A'])
					continue;
				else
					board[nx][ny] = '.';
			}
			if ('a' <= board[nx][ny] && board[nx][ny] <= 'z') {
				has_keys[board[nx][ny] - 'a'] = true;
				board[nx][ny] = '.';
				return false;
			}

			if (board[nx][ny] == '$') {
				board[nx][ny] = '.';
				res++;
			}

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		res = 0;
		cin >> H >> W;

		for (int i = 0; i <= H + 1; i++) {
			for (int j = 0; j <= W + 1; j++)
				board[i][j] = '.';
		}

		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++)
				cin >> board[i][j];
		}

		memset(has_keys, false, sizeof(has_keys));
		string key;
		cin >> key;

		if (key != "0") {
			for (char ch : key)
				has_keys[ch - 'a'] = true;
		}

		do {
			memset(vis, 0, sizeof(vis));
		} while (!bfs());

		cout << res << '\n';
	}
}