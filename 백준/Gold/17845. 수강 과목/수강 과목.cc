#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 10001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, K;
int w[BOUND], v[BOUND], mem[BOUND][BOUND];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 1; i <= K; i++)
		cin >> v[i] >> w[i]; // 중요도, 공부시간

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (w[i] <= j)
				mem[i][j] = max(mem[i - 1][j], v[i] + mem[i - 1][j - w[i]]);
			else
				mem[i][j] = mem[i - 1][j];
		}
	}

	cout << mem[K][N];
	return 0;
}