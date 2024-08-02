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
ll A, X;
/***********************/

ll f_pow(ll cur) {
	if (cur == 0)
		return 1;
	if (cur == 1)
		return A % MOD;

	ll tmp = f_pow(cur / 2);

	if (cur & 1)
		return (((tmp % MOD) * (tmp % MOD) % MOD) * (A % MOD)) % MOD;
	else
		return ((tmp % MOD) * (tmp % MOD)) % MOD;
}



int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> A >> X;
	cout << f_pow(X);

	return 0;
}