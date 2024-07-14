#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1000001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N;
int lo = -1, hi = -1, max_v = -1;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int x, i = 0; i < N; i++) {
		cin >> x;

		if (x > max_v) {
			max_v = x;
			lo = i;
			hi = i;
		}
		else if (x == max_v)
			hi = i;
	}

	if (lo > (N - 1) - hi)
		cout << "B";
	else if (lo < (N - 1) - hi)
		cout << "R";
	else
		cout << "X";

	return 0;
}