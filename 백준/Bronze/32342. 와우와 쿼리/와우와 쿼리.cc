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
int Q;
string S;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> Q;

	while (Q--) {
		cin >> S;

		int cnt = 0, len = S.size();
		for (int i = 0; i < len - 2; i++) {
			if (S.substr(i, 3) == "WOW")
				cnt++;
		}

		cout << cnt << "\n";
	}

	return 0;
}