#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
string A, B, C;
/***********************/


int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> A >> B >> C;
	cout << stoi(A) + stoi(B) - stoi(C) << "\n";
	cout << stoi(A + B) - stoi(C);

	return 0;
}