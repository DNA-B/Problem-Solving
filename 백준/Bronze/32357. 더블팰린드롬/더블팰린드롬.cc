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
int N, cnt = 0;
string S;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		cin >> S;

		string rv_S = S;
		reverse(rv_S.begin(), rv_S.end());

		if (S == rv_S)
			cnt++;
	}

	cout << cnt * (cnt - 1);
	return 0;
}