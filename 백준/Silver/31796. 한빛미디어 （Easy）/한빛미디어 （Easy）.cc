#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, min_price = -1, page = 0;
int arr[100001];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		if (2 * min_price <= arr[i]) {
			page++;
			min_price = arr[i];
		}
	}

	cout << page;
	return 0;
}