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
int T, N;
int mem[1005];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 1; i <= 1000; i++) {
		mem[i] = 1;
		for (int j = 0; j < i; j++) {
			if ((i - j) % 2 == 0)
				mem[i] += mem[(i - j) / 2];
		}
	}

	cin >> T;

	while (T--) {
		cin >> N;
		cout << mem[N] << '\n';
	}

	return 0;
}