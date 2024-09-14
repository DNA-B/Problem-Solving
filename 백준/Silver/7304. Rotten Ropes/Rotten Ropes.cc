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
int ropes[1005];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		int mx = -1;

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> ropes[i];
		sort(ropes, ropes + N, greater<int>());
		for (int i = 0; i < N; i++) // [i+1] --> cnt
			mx = max(mx, ropes[i] * (i + 1));

		cout << mx << '\n';
	}

	return 0;
}