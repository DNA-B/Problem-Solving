#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int N;
ll x, mx = -1;
map<ll, int> m;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		m[x]++;
	}

	for (auto item : m) {
		if ((item.Y / 2) > 0)
			m[item.X * 2] += item.Y / 2;
		mx = max(mx, (item.X));
	}

	cout << mx;
	return 0;
}