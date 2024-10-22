#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1000005
#define MOD 1'000'000'007
#define PI 3.14159265358979323846
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, r, e, c;
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		cin >> r >> e >> c;

		if (r == e - c)
			cout << "does not matter\n";
		else if (r > e - c)
			cout << "do not advertise\n";
		else
			cout << "advertise\n";
	}

	return 0;
}