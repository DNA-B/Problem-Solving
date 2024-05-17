#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 10
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, M;
int mission[2][3];
int res = 0;
/***********************/

void solve(int prev, int cur, int cnt) {
	if (cnt == N) {
		if (cur >= M)
			res++;

		return;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if (prev == j) // 같은 장소에서 일했음
				solve(j, cur + (mission[i][j] / 2), cnt + 1);
			else
				solve(j, cur + mission[i][j], cnt + 1);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> mission[i][j];

	solve(-1, 0, 0);
	cout << res;

	return 0;
}