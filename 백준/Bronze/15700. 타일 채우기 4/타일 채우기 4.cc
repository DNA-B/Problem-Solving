#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 1001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
ll N, M;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	cout << (N * M) / 2;

	return 0;
}