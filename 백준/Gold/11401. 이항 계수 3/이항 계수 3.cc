#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1000000007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, K;
ll A = 1, B = 1;
/***********************/

ll solve(int x) {
	if (x == 0)
		return 1;

	ll tmp = solve(x / 2) % MOD;
	tmp = (tmp * tmp) % MOD;

	if (x % 2 == 0)
		return tmp % MOD;
	else
		return (B * tmp) % MOD;
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	// N * (N - 1) *  .... * (N - K + 1)
	for (int i = N - K + 1; i <= N; i++)
		A = (A * i) % MOD;

	// K!
	for (int i = 1; i <= K; i++)
		B = (B * i) % MOD;

	// (K!)^(p - 2)
	B = solve(MOD - 2);

	cout << (A * B) % MOD;
	return 0;
}