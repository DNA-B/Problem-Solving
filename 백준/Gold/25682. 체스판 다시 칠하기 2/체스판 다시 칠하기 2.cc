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
int N, M, K, res = INT_MAX;
int B[2005][2005], W[2005][2005];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		bool flag = i % 2;
		for (int j = 1; j <= M; j++) {
			B[i][j] = W[i][j] = flag;
			flag = !flag;
		}
	}

	for (int i = 1; i <= N; i++) {
		char ch;
		for (int j = 1; j <= M; j++) {
			cin >> ch;
			B[i][j] ^= (ch == 'B');
			W[i][j] ^= (ch == 'W');

			B[i][j] = B[i][j] + B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
			W[i][j] = W[i][j] + W[i - 1][j] + W[i][j - 1] - W[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= N - K + 1; i++) {
		for (int j = 1; j <= M - K + 1; j++) {
			int tmpB = B[i + K - 1][j + K - 1] - B[i - 1][j + K - 1] - B[i + K - 1][j - 1] + B[i - 1][j - 1];
			int tmpW = W[i + K - 1][j + K - 1] - W[i - 1][j + K - 1] - W[i + K - 1][j - 1] + W[i - 1][j - 1];
			res = min({ res, tmpB, tmpW });
		}
	}

	cout << res;
	return 0;
}