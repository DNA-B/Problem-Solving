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
int a, b, c, d;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> a >> b >> c >> d >> N;

	int u, v;
	while (N--) {
		cin >> u >> v;
		if (max(a * (v - b) * (v - b) + c, d) == u) cnt++;
	}

	cout << cnt;
	return 0;
}