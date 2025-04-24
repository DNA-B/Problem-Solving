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
int N, M, cnt = 0;
int vis[55][55];
char arr[55][55];
//=========================//

void solve(int mode, int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return;
	if (vis[x][y])
		return;

	if (mode == 1 && arr[x][y] == '-') {
		vis[x][y] = 1;
		solve(mode, x, y + 1);
		solve(mode, x, y - 1);
	}
	else if (mode == 0 && arr[x][y] == '|') {
		vis[x][y] = 1;
		solve(mode, x + 1, y);
		solve(mode, x - 1, y);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!vis[i][j]) {
				if (arr[i][j] == '-') solve(1, i, j);
				else solve(0, i, j);
				cnt++;
			}
		}
	}

	cout << cnt;
}