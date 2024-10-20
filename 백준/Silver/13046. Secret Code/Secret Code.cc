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
bool chk[205];
string S, cmp;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> S >> N;

	for (char ch : S)
		chk[ch] = true;

	while (N--) {
		int cor = 0, diff = 0;
		cin >> cmp;
		for (int i = 0; i < S.size(); i++) {
			if (chk[cmp[i]] && cmp[i] == S[i])
				cor++;
			else if (chk[cmp[i]] && cmp[i] != S[i])
				diff++;
		}
		cout << cor << ' ' << diff << '\n';
	}

	return 0;
}