#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 200001
#define MOD 1'000'000'007
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N;
int res = -1;
int lp = 0, rp = 0;
int cnt[10];
int arr[BOUND];
/***********************/

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	while (rp < N) {
		cnt[arr[rp++]]++; // 현재 위치의 과일 개수 추가

		while (count(cnt, cnt + 10, 0) < 8)
			cnt[arr[lp++]]--;

		res = max(res, rp - lp);
	}

	cout << res;

	return 0;
}