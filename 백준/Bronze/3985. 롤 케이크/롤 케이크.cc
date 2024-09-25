#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
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
int L, N;
int pmx = -1, pidx = -1, rmx = -1, ridx = -1;
bool cake[1005];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> L >> N;

	int p, k;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;

		cin >> p >> k;

		if (k - p + 1 > pmx) {
			pmx = k - p + 1;
			pidx = i;
		}

		for (int j = p; j <= k; j++) {
			if (!cake[j]) {
				cnt++;
				cake[j] = true;
			}
		}

		if (cnt > rmx) {
			rmx = cnt;
			ridx = i;
		}
	}

	cout << pidx << '\n' << ridx;
	return 0;
}