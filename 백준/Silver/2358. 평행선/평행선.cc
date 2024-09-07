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
int N, res = 0;
unordered_map<int, int> umx, umy;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	int x, y;
	while (N--) {
		cin >> x >> y;
		umx[x]++, umy[y]++;
	}

	for (auto [x, cnt] : umx)
		if (cnt >= 2) res++;
	for (auto [y, cnt] : umy)
		if (cnt >= 2) res++;

	cout << res;
	return 0;
}