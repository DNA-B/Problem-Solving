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
bool x;
int N, M;
int mem[305][305];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> x;
			mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]) + x;
		}
	}

	cout << mem[N][M];
	return 0;
}