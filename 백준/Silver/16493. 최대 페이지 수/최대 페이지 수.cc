#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M;
int mem[25][205], W[25], V[25];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> W[i] >> V[i];

		for (int j = 1; j <= N; j++) {
			if (j - W[i] >= 0)
				mem[i][j] = max(mem[i - 1][j], mem[i - 1][j - W[i]] + V[i]);
			else
				mem[i][j] = mem[i - 1][j];
		}
	}

	cout << mem[M][N];
	return 0;
}