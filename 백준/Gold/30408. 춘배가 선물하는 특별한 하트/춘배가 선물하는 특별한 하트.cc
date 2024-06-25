#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

/******** MACRO ********/
#define BOUND 1000005
#define MOD 1'000'000'007
#define PI 3.14159265358979323846
#define ll long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
ll N, M;
map<ll, bool> m;
/***********************/

void div_choco(ll cur) {
	if (cur == 0)
		return;
	if (cur == 1)
		return;
	if (m[cur] == true)
		return;

	if (cur % 2 == 0) {
		div_choco(cur / 2);
		m[cur / 2] = true;
	}
	else {
		div_choco((cur - 1) / 2);
		div_choco((cur - 1) / 2 + 1);
		m[(cur - 1) / 2] = true;
		m[(cur - 1) / 2 + 1] = true;
	}

	return;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	div_choco(N);
	m[N] = true;
	cout << (m[M] ? "YES" : "NO");

	return 0;
}