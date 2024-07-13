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
int N, m, M, T, R; // 운동 N분, 최소맥박, 최대맥박, T만큼 증가, R만큼 감소
/***********************/

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> m >> M >> T >> R;

	if (M - m < T) {
		cout << -1;
		exit(0);
	}

	int x = m, ex = 0, cnt = 0;
	while (ex < N) {
		if (x + T <= M) {
			x += T;
			ex++;
		}
		else
			x = max(m, x - R);

		cnt++;
	}

	cout << cnt;
	return 0;
}