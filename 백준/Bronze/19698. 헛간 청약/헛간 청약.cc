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
int N, W, H, L;
int max_cow;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> W >> H >> L;
	max_cow = (W / L) * (H / L);
	cout << (N < max_cow ? N : max_cow);

	return 0;
}