#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, K;
int arr[301][301], psum[301][301];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + arr[i][j];
		}
	}

	cin >> K;

	while (K--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << psum[x][y] - psum[i - 1][y] - psum[x][j - 1] + psum[i - 1][j - 1] << '\n';
	}

	return 0;
}