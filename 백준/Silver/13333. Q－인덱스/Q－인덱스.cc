#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
int res = -1;
int k[BOUND];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> k[i];

	sort(k, k + N);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			if (k[j] >= i && N - j >= i) {
				res = i;
				break;
			}
		}
	}

	cout << res;
	return 0;
}