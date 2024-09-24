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

	if (N == 1) {
		cout << 11 << '\n';
		cout << "A B C D E F G H J L M";
	}
	else if (N == 2) {
		cout << 9 << '\n';
		cout << "A C E F G H I L M";
	}
	else if (N == 3) {
		cout << 9 << '\n';
		cout << "A C E F G H I L M";
	}
	else if (N == 4) {
		cout << 9 << '\n';
		cout << "A B C E F G H L M";
	}
	else if (N == 5) {
		cout << 8 << '\n';
		cout << "A C E F G H L M";
	}
	else if (N == 6) {
		cout << 8 << '\n';
		cout << "A C E F G H L M";
	}
	else if (N == 7) {
		cout << 8 << '\n';
		cout << "A C E F G H L M";
	}
	else if (N == 8) {
		cout << 8 << '\n';
		cout << "A C E F G H L M";
	}
	else if (N == 9) {
		cout << 8 << '\n';
		cout << "A C E F G H L M";
	}
	else if (N == 10) {
		cout << 8 << '\n';
		cout << "A B C F G H L M";
	}

	return 0;
}