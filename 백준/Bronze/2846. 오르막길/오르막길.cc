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
int N, x, mx = -1;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> x;

	int st = x, en = x;
	for (int i = 0; i < N - 1; i++) {
		cin >> x;

		if (x <= en) {
			mx = max(mx, en - st);
			st = x;
		}

		en = x;
	}

	mx = max(mx, en - st);
	cout << mx;

	return 0;
}