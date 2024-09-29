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
int N, p, q, r, s;
int arr[25];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> p >> q >> r >> s >> arr[1];

	for (int i = 2; i <= N; i++) {
		if (i & 1)
			arr[i] = r * arr[i / 2] + s;
		else
			arr[i] = p * arr[i / 2] + q;
	}

	cout << accumulate(arr + 1, arr + (N + 1), 0L);
	return 0;
}