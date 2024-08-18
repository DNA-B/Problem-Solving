#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, mx = INT_MAX;
int res[2], arr[200005];
/***********************/

int b_search(int idx) {
	int lo = idx + 1, hi = N - 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (arr[idx] + arr[mid] == 0)
			return mid;
		else if (arr[idx] + arr[mid] < 0)
			lo = mid;
		else
			hi = mid;
	}

	if (abs(arr[idx] + arr[lo]) < abs(arr[idx] + arr[hi]))
		return lo;
	else
		return hi;
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	for (int i = 0; i < N - 1; i++) {
		int idx = b_search(i);

		if (mx > abs(arr[i] + arr[idx])) {
			mx = abs(arr[i] + arr[idx]);
			tie(res[0], res[1]) = { arr[i], arr[idx] };
		}
	}

	cout << res[0] << ' ' << res[1];
	return 0;
}