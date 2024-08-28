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
int N;
int arr[55];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		arr[x]++;
	}

	for (int i = 50; i >= 0; i--) {
		if (arr[i] == i) {
			cout << i;
			exit(0);
		}
	}

	cout << -1;
	return 0;
}