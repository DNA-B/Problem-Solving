#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 100001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int A, B, C;
/***********************/


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> A >> B >> C;
	cout << (A + B == C ? "correct!" : "wrong!");

	return 0;
}