#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int R, C;
int mnx = INT_MAX, mxx = -1, mny = INT_MAX, mxy = -1;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int sea[15][15];
char board[15][15];
//=========================//

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


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'X') {
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (nx < 0 || nx >= R || ny < 0 || ny >= C)
						sea[i][j]++;
					else if (board[nx][ny] == '.')
						sea[i][j]++;
				}
			}
		}
	}


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'X' && sea[i][j] < 3) {
				mnx = min(mnx, i);
				mxx = max(mxx, i);
				mny = min(mny, j);
				mxy = max(mxy, j);
			}
		}
	}


	for (int i = mnx; i <= mxx; i++) {
		for (int j = mny; j <= mxy; j++) {
			if (board[i][j] == '.' || sea[i][j] >= 3)
				cout << '.';
			else
				cout << 'X';
		}
		cout << '\n';
	}
}