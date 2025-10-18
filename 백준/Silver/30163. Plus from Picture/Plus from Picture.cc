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
int H, W, cnt = 0;
char board[505][505];
//=========================//


void clean(int x, int y) {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	board[x][y] = '.';
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		while ((0 <= nx && nx < H && 0 <= ny && ny < W) && board[nx][ny] == '*') {
			board[nx][ny] = '.';
			nx += dx[dir];
			ny += dy[dir];
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cin >> board[i][j];
	}

	for (int i = 1; i < H; i++) {
		for (int j = 1; j < W; j++) {
			if (board[i][j] == '*' 
                && board[i - 1][j] == '*' 
                && board[i + 1][j] == '*' 
                && board[i][j - 1] == '*' 
                && board[i][j + 1] == '*') {
                
				clean(i, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < H; i++) { // '+' 제외 나머지 셀 비어있어야 함.
		for (int j = 0; j < W; j++) {
			if (board[i][j] == '*') {
				cout << "NO";
				exit(0);
			}
		}
	}

	cout << (cnt == 1 ? "YES" : "NO"); // '+' 모양은 정확히 1개
}