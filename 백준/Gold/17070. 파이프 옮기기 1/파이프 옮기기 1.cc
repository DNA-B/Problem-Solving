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
int N;
int board[20][20], mem[3][20][20]; // 0: 가로, 1: 세로, 2: 대각선
//=========================//

void solve(int mode, int x, int y) {
	if (mode == 0) // 가로 밀기 + 대각선 회전
		mem[mode][x][y] += mem[0][x][y - 1] + mem[2][x][y - 1];
	else if (mode == 1) // 세로 밀기 + 대각선 회전
		mem[mode][x][y] += mem[1][x - 1][y] + mem[2][x - 1][y];
	else if (mode == 2) // 가로 회전 + 세로 회전 + 대각선 밀기
		mem[mode][x][y] += mem[0][x - 1][y - 1] + mem[1][x - 1][y - 1] + mem[2][x - 1][y - 1];
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	}

	mem[0][1][2] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j])
				continue;
			if (!board[i][j - 1]) // 가로
				solve(0, i, j);
			if (!board[i - 1][j]) // 세로
				solve(1, i, j);
			if (!board[i][j - 1] && !board[i - 1][j] && !board[i - 1][j - 1]) // 대각선
				solve(2, i, j);
		}
	}

	cout << mem[0][N][N] + mem[1][N][N] + mem[2][N][N];
}