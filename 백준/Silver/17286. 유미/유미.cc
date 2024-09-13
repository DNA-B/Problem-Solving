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
int res = INT_MAX;
pair<int, int> yumi;
pair<int, int> peoples[3];
bool vis[3];
/***********************/

double get_dist(pair<int, int> a, pair<int, int> b) {
	return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}

void solve(pair<int, int> cur, int cnt, double len) {
	if (cnt == 3) {
		res = min(res, (int)len);
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (!vis[i]) {
			vis[i] = true;
			solve(peoples[i], cnt + 1, len + get_dist(cur, peoples[i]));
			vis[i] = false;
		}
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> yumi.X >> yumi.Y;

	for (int i = 0; i < 3; i++)
		cin >> peoples[i].X >> peoples[i].Y;

	solve(yumi, 0, 0);
	cout << res;

	return 0;
}