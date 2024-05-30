#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 101
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
typedef vector<vector<ll>> matrix;
ll N;
matrix res = { {1, 0}, {1, 0} };
matrix mul_mat = { {1, 1}, {1, 0} };
/***********************/

matrix operator*(matrix& mat_a, matrix& mat_b) {
	matrix tmp(2, vector<ll>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				tmp[i][j] += (mat_a[i][k] * mat_b[k][j]) % MOD;
			tmp[i][j] %= MOD;
		}
	}

	return tmp;
}

void solve() {
	while (N > 0) {
		if (N & 1)
			res = res * mul_mat;
		mul_mat = mul_mat * mul_mat;
		N /= 2;
	}
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	/*
		피보나치의 행렬곱 결과는 n번 제곱하였을 때
		An+1, An
		An, An-1
		이므로 res[1][0]이나 res[0][1]을 출력하면 n번째 피보나치 수를 얻을 수 있다.
	*/

	cin >> N;
	solve();
	cout << res[0][1];

	return 0;
}