#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 50001
#define INF 0x3f3f3f3f
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, K;
int deadline[BOUND];
/***********************/

bool is_possible(int x) {
	for (int i = 1; i <= N; i++) {
		if (x * i > deadline[i])
			return false;
	}

	return true;
}

int b_search() {
	int lo = 1, hi = 1'000'000'001;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (is_possible(mid))
			lo = mid;
		else
			hi = mid;
	}

	return lo;
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> deadline[i];

	sort(deadline + 1, deadline + (N + 1));
	cout << b_search();

	return 0;
}