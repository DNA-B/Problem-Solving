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
ll cost = 0, cur = 0;
int N;
int arr[500005];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cur += arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N - 1; i++) {
		cur -= arr[i];
		cost += cur * arr[i];

	}

	cout << cost;
	return 0;
}