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
int N, res = 0;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int board[105][105];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int x, y;
	while (N--) {
		cin >> x >> y;
		for (int i = y; i < y + 10; i++) {
			for (int j = x; j < x + 10; j++)
				board[i][j] = 1;
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (board[i][j] == 1) {
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if (!board[nx][ny])
						res++;
				}
			}
		}
	}

	cout << res;
}