#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int K, N = 2, pow_cnt;
/***********************/

int solve() {
	bitset<32> K_to_bit;
	bitset<32> N_to_bit(N);
	int K_cnt = 0, N_cnt = 0;

	K_to_bit = K & -K; // 마지막 비트만 남기고 다 제거

	for (int i = 0; i < 32; i++) {
		if (N_to_bit[i])
			N_cnt = i;
		if (K_to_bit[i])
			K_cnt = i;
	}

	return N_cnt - K_cnt;
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> K;
	cout << fixed << setprecision(0);

	while (N < K)
		N <<= 1;

	cout << N << " " << solve();
	return 0;
}