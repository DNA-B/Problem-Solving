#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1000001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
int x, y, z;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	if (N == 2) {
		cin >> x >> y;

		for (int i = 1; i <= min(x, y); i++) {
			if (x % i == 0 && y % i == 0)
				cout << i << "\n";
		}
	}
	else {
		cin >> x >> y >> z;

		for (int i = 1; i <= min({ x, y, z }); i++) {
			if (x % i == 0 && y % i == 0 && z % i == 0)
				cout << i << "\n";
		}
	}

	return 0;
}