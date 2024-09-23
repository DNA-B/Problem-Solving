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
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N - i; j++)
			cout << ' ';
		for (int j = 0; j < i; j++)
			cout << '*';
		cout << '\n';
	}

	for (int i = N; i < 2 * N - 1; i++) {
		for (int j = 0; j < i - N + 1; j++)
			cout << ' ';
		for (int j = 0; j < (2 * N - 1) - i; j++)
			cout << '*';
		cout << '\n';
	}

	return 0;
}