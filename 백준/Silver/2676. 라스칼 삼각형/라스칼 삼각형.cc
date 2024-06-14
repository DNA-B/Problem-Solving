#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1001
#define MOD 1'000'000'007
#define PI 3.14159265358979323846
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, N, M;
/***********************/


/*
                    1
                1       1
            1       2       1
        1       3       3       1
    1       4       5       4       1
1       5       7       7       5       1

일반항 = 1 + (n - m - 1 + 1) m
최댓값 : 1 + (50000 - 25000) 25000
*/

int rascal(int n, int m) {
	return 1 + (n - m) * m;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cin >> N >> M;

		if (N < 0 || M < 0 || N < M)
			cout << 0 << "\n";
		else if (M == 0 || M == N)
			cout << 1 << "\n";
		else
			cout << rascal(N, M) << "\n";
	}

	return 0;
}