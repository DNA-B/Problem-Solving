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
int N, K, idx = -1, cur = 0, mx = -1;
int arr[1000005];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int g, x, i = 0; i < N; i++) {
		cin >> g >> x;
		idx = max(idx, x);
		arr[x] = g;
	}

	for (int i = 0; i <= idx; i++) {
		if (i >= 2 * K + 1) cur -= arr[i - (2 * K + 1)]; // 이전 윈도우 첫 값 제거
		cur += arr[i]; // 새로운 값 윈도우에 추가
		mx = max(mx, cur);
	}

	cout << mx;
	return 0;
}