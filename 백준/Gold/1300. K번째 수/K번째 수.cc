#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
ll N, K;
/***********************/

ll check(ll x) {
	ll cnt = 0;
	for (int i = 1; i <= N; i++) // i의 배수 중에서 x 이하인 값들 count
		cnt += min(x / i, N);
	return cnt;
}

ll b_search() {
	ll lo = 0, hi = N * N;

	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll cnt = check(mid);

		if (cnt >= K)
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	cout << b_search();

	return 0;
}