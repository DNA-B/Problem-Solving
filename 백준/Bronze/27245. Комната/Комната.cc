#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 21
#define MOD 1'000'000'007
#define PI 3.14159265358979323846
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int W, L, H;
bool is_good = true;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> W >> L >> H;

	if (min(W, L) < 2 * H)
		is_good = false;
	if (max(W, L) / min(W, L) > 2)
		is_good = false;

	cout << (is_good ? "good" : "bad");

	return 0;
}