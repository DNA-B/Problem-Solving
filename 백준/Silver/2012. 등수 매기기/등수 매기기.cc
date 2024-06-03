#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 500001
#define MOD 1'000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N;
ll res = 0;
ll pred[BOUND];
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> pred[i];

	sort(pred + 1, pred + (N + 1));

	for (int i = 1; i <= N; i++)
		res += abs(pred[i] - i);

	cout << res;

	return 0;
}