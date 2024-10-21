#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define PI 3.1415926535897932
#define MOD 1000000007
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, H;
ll mem[1005][1005];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> mem[i][j];

			if (i - 1 >= 1 && j - 1 >= 1) // 둘 다 범위 안
				mem[i][j] += min(mem[i - 1][j], mem[i][j - 1]);
			else if (i - 1 >= 1) // row만 범위 안
				mem[i][j] += mem[i - 1][j];
			else if (j - 1 >= 1) // col만 범위 안
				mem[i][j] += mem[i][j - 1];
		}
	}

	cin >> H;

	if (H >= mem[N][M])
		cout << "YES\n" << mem[N][M];
	else
		cout << "NO";

	return 0;
}