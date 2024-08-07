#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
/***********************/


int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < 3; i++) {
		int x;
		bool flag = false;

		for (int j = 0; j < N; j++) {
			cin >> x;
			if (x == 7) flag = true;
		}

		if (!flag) {
			cout << 0;
			exit(0);
		}
	}

	cout << 777;
	return 0;
}