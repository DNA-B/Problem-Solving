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
int x;
int res[15];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	for (int i = 0; i < 2047; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> x;
			res[j] ^= x;
		}
	}

	for (int i = 0; i < 11; i++)
		cout << res[i] << ' ';

	return 0;
}