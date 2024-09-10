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
int N = 5, x;
int arr[10];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (N--) {
		cin >> x;
		arr[x]++;
	}

	for (int i = 0; i < 10; i++) {
		if (arr[i] > 0 && arr[i] % 2) {
			cout << i;
			break;
		}
	}

	return 0;
}