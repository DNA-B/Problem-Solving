#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

/******** MACRO ********/
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define MOD 1'000'000'007
#define PI 3.1415926535897932
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, M, res = INT_MAX;
int student[15];
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int solve, pn;
		cin >> solve;

		for (int j = 0; j < solve; j++) {
			cin >> pn;
			student[i] |= (1 << pn);
		}
	}

	for (int i = 0; i < (1 << M); i++) {
		int comb = 0, cnt = 0, sn = 0;

		for (int stu = 0; stu < M; stu++) {
			if ((i & (1 << stu)) != 0) {
				comb |= student[stu];
				sn++;
			}
		}

		for (int prob = 1; prob <= N; prob++)
			cnt += (comb >> prob) & 1;

		if (cnt >= N)
			res = min(res, sn);
	}

	cout << (res == INT_MAX ? -1 : res);
	return 0;
}