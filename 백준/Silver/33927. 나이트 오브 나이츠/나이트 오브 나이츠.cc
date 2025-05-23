#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int N, mx = -1;
int board[5][5], vis[5][5];
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
//=========================//

bool is_possible(int x, int y) {
	for (int dir = 0; dir < 8; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (vis[nx][ny]) // 서로 공격 가능한 말이 있음
			return false;
	}

	return true;
}

void solve(int x, int y, int score) {
	mx = max(mx, score);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j] && is_possible(i, j)) {
				vis[i][j] = 1;
				solve(i, j, score + board[i][j]);
				vis[i][j] = 0;
			}
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			memset(vis, 0, sizeof(vis));
			vis[i][j] = 1;
			solve(i, j, board[i][j]);
			vis[i][j] = 0;
		}
	}

	cout << mx;
}