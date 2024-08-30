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
int N, A = 1;
int vis[10];
/***********************/

void print() {
	for (int i = 0; i < N; i++)
		cout << vis[i] << ' ';
	exit(0);
}

void solve(int cnt, int cur) {
	if (cnt > N)
		return;
	if (cnt == N) {
		if (cur > A)
			print();
		return;
	}

	for (int i = 1; i <= 9; i++) {
		vis[cnt] = i;
		solve(cnt + 1, cur * i);
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		A *= x;
	}

	solve(0, 1);
	cout << -1;
	return 0;
}