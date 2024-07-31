#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INF 0x3f3f3f3f
#define LLINF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int T, a, b;
string s;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		cin >> a >> b >> s;
		for (char& ch : s) {
			ch = ((a * (ch - 'A') + b) % 26) + 'A';
		}
		cout << s << "\n";
	}

	return 0;
}