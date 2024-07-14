#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 10001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, K, cnt = 0;
int arr[BOUND];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = N - 1; i > 0; i--) {
		int max_idx = max_element(arr, arr + i + 1) - arr;

		if (max_idx != i) {
			cnt++;
			swap(arr[max_idx], arr[i]);
		}

		if (cnt == K)
			break;
	}

	if (cnt < K) {
		cout << -1;
		exit(0);
	}

	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";

	return 0;
}