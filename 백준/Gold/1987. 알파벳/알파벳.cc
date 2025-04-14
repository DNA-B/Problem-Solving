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
int R, C, mx = -1;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0 , 1, -1 };
char board[25][25];
map<char, bool> dict;
//=========================//

void solve(int len, int x, int y) {
	mx = max(mx, len);

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			continue;
		if (dict[board[nx][ny]])
			continue;

		dict[board[nx][ny]] = true;
		solve(len + 1, nx, ny);
		dict[board[nx][ny]] = false;
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
	}

	dict[board[0][0]] = true;
	solve(1, 0, 0);
	cout << mx;
}