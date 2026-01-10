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
string S;
int N, M;
char board[105][105];
int dx[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int dy[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
//=========================//

void solve(int x, int y) {
	for (int dir = 0; dir < 8; dir++) {
		bool flag = true;
		int cur_x = x, cur_y = y;
		for (int idx = 1; idx < S.length(); idx++) { // x, y는 S[0]과 일치하므로 1부터
			int nx = cur_x + dx[dir];
			int ny = cur_y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
				flag = false;
				break;
			}
			if (board[nx][ny] != S[idx]) {
				flag = false;
				break;
			}

			cur_x = nx;
			cur_y = ny;
		}

		if (flag) {
			cout << 1;
			exit(0);
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == S[0])
				solve(i, j);
		}
	}

	cout << 0;
}