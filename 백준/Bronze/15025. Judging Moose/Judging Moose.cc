#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 2002
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int l, r;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> l >> r;

	if (l == 0 && r == 0)
		cout << "Not a moose";
	else if (l == r)
		cout << "Even " << l + r;
	else if (l != r)
		cout << "Odd " << max(l, r) * 2;

	return 0;
}