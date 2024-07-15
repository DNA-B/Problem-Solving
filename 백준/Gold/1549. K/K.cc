#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 3001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
ll min_sub = INT_MAX, min_k = INT_MAX;
ll psum[BOUND];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int x, i = 1; i <= N; i++) {
		cin >> x;
		psum[i] = psum[i - 1] + x;
	}

	for (int k = N / 2; k > 0; k--) {
		for (int i = 1; i <= N - k; i++) {
			for (int j = i + k; j <= N - k + 1; j++) {
				ll tmp = abs((psum[i + k - 1] - psum[i - 1]) - (psum[j + k - 1] - psum[j - 1]));

				if (tmp < min_sub) {
					min_sub = tmp;
					min_k = k;
				}
			}
		}
	}

	cout << min_k << "\n" << min_sub;
	return 0;
}