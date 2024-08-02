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
ll A, X, res = 1;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> A >> X;

	while (X) {
		if (X & 1)
			res = ((res % MOD) * (A % MOD)) % MOD;

		A = ((A % MOD) * (A % MOD)) % MOD;
		X >>= 1;
	}

	cout << res;
	return 0;
}