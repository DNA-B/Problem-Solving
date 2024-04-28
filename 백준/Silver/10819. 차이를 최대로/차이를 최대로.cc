#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N;
int res = -INT_MAX;
int arr[BOUND];
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	do {
		int total = 0;

		for (int i = 1; i < N; i++)
			total += abs(arr[i] - arr[i - 1]);

		res = max(res, total);
	} while (next_permutation(arr, arr + N));

	cout << res;

	return 0;
}