#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 1'000'001
#define MAX 1'000'000'001
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, M;
int snack[BOUND];
/***********************/


bool check(int cur) {
	long long cnt = 0; // 과자가 모두 BOUND면 overflow 발생 가능

	for (int i = 0; i < N; i++)
		cnt += snack[i] / cur;

	return cnt >= M;
}

int binary_search() {
	int st = 0, en = MAX; // 과자는 1 ~ MAX까지의 값을 가질 수 있다. 또한 T -> F로 바뀌는 문제이므로 st를 반환

	while (st + 1 < en) {
		int mid = (st + en) / 2;

		if (check(mid))
			st = mid;
		else
			en = mid;
	}

	return st;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
		cin >> snack[i];

	cout << binary_search();

	return 0;
}