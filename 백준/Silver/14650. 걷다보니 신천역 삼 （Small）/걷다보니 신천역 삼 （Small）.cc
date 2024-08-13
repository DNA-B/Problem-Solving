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
int N, cnt = 0;
string s = "";
/***********************/

void solve(int idx) {
	if (s.size() == N) {
		if (stoi(s) % 3 == 0) cnt++;
		return;
	}

	for (int i = idx; i < 3; i++) {
		s += i + '0';
		solve(0);
		s.pop_back();
	}
}

int main() {
	cin.tie(NULL)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	solve(1);
	cout << cnt;
	return 0;
}