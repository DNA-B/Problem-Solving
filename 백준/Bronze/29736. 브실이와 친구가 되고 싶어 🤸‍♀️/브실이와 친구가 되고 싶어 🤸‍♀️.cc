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
int A, B, K, X;
int cnt = 0;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> A >> B >> K >> X;
	cnt += min(K + X, B) - max(K - X, A) + 1;

	if (cnt <= 0)
		cout << "IMPOSSIBLE";
	else
		cout << cnt;

	return 0;
}