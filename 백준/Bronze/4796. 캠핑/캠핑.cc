#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 101
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int L, P, V;
int tc = 0, res = 0;
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (1) {
		res = 0;
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0)
			break;

		res += L * (V / P);
		res += (V % P > L) ? L : V % P;
		cout << "Case " << ++tc << ": " << res << "\n";
	}

	return 0;
}