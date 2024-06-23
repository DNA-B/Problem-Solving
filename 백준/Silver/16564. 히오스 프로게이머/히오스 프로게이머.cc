#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1000001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, K;
int level[BOUND];
/***********************/

int solve(ll st, ll en) {
	while (st + 1 < en) {
		int mid = (st + en) / 2;
		ll sub = 0;

		for (int i = 0; i < N; i++) {
			if (level[i] < mid)
				sub += mid - level[i];
		}

		if (sub <= K)
			st = mid;
		else
			en = mid;
	}

	return st;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> level[i];

	cout << solve(1, 2000000001); // 1명이고 K가 1000000000일 때 2000000000까지 가능

	return 0;
}