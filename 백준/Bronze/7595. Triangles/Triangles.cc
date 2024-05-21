#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 200001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N;
/***********************/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);

	while (cin >> N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++)
				cout << "*";
			cout << "\n";
		}
	}

	return 0;
}