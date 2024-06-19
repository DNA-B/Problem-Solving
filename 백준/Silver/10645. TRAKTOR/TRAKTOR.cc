#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1000005
#define MOD 1'000'000'007
#define PI 3.14159265358979323846
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, K;
map<int, int> X, Y, diag1, diag2;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int x, y, i = 1; i <= N; i++) {
		cin >> x >> y;

		X[x]++;
		Y[y]++;
		diag1[x + y]++;
		diag2[x - y]++;

		if (X[x] == K || Y[y] == K || diag1[x + y] == K || diag2[x - y] == K) {
			cout << i;
			exit(0);
		}
	}

	cout << -1;
	return 0;
}