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
int T, N;
int r1, r2, c1, c2;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> N >> r1 >> c1 >> r2 >> c2;
		cout << "Case " << i << ": ";

		if (r1 - 1 == r2 && c1 + 2 == c2)
			cout << "YES\n";
		else if (r1 - 1 == r2 && c1 - 2 == c2)
			cout << "YES\n";
		else if (r1 + 1 == r2 && c1 + 2 == c2)
			cout << "YES\n";
		else if (r1 + 1 == r2 && c1 - 2 == c2)
			cout << "YES\n";
		else if (r1 + 2 == r2 && c1 - 1 == c2)
			cout << "YES\n";
		else if (r1 + 2 == r2 && c1 + 1 == c2)
			cout << "YES\n";
		else if (r1 - 2 == r2 && c1 - 1 == c2)
			cout << "YES\n";
		else if (r1 - 2 == r2 && c1 + 1 == c2)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}