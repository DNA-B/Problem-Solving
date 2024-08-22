#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N, C;
int arr[200005];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> C;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	int lo = 1, hi = arr[N - 1] - arr[0] + 1;
	while (lo + 1 < hi) {
		int cur = arr[0], cnt = 1;
		int mid = (lo + hi) / 2;

		for (int i = 1; i < N; i++) {
			if (arr[i] - cur >= mid) {
				cnt++;
				cur = arr[i];
			}
		}

		if (cnt >= C)
			lo = mid;
		else
			hi = mid;
	}

	cout << lo;
	return 0;
}