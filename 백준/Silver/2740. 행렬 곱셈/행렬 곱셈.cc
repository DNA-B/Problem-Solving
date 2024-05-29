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
int N, M, K;
int arrA[BOUND][BOUND], arrB[BOUND][BOUND], res[BOUND][BOUND];
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arrA[i][j];

	cin >> M >> K;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> arrB[i][j];

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < K; k++) {
			for (int j = 0; j < M; j++)
				res[i][k] += arrA[i][j] * arrB[j][k];
			cout << res[i][k] << " ";
		}
		cout << "\n";
	}

	return 0;
}