#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int a, b;
int ga, se;
/***********************/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> a >> b;

	a--;
	b--;
	ga = abs((a / 4) - (b / 4));
	se = abs((a % 4) - (b % 4));

	cout << ga + se;

	return 0;
}