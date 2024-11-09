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
int N, M;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int arr[505][505], mem[505][505];
//=========================//

int dfs(int x, int y) {
	if (x == N && y == M)
		return 1;
	if (mem[x][y] != -1)
		return mem[x][y];

	mem[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 1 || nx > N || nx < 1 || ny > M)
			continue;
		if (arr[x][y] > arr[nx][ny])
			mem[x][y] += dfs(nx, ny);
	}

	return mem[x][y];
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];
		fill(mem[i], mem[i] + (M + 1), -1);
	}

	cout << dfs(1, 1);
	return 0;
}