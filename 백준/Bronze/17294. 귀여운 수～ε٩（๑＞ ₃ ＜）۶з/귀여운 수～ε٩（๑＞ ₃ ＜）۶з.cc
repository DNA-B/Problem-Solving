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
string S;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> S;

	if (S.size() == 1 || S.size() == 2) {
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
		exit(0);
	}

	int prev = S[1] - S[0];
	for (int i = 2; i < S.size(); i++) {
		if (prev != S[i] - S[i - 1]) {
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
			exit(0);
		}
		prev = S[i] - S[i - 1];
	}

	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	return 0;
}