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
/***********************/

double get_dist(pair<int, int> a, pair<int, int> b) {
	return sqrt(pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2));
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> yumi.X >> yumi.Y;

	for (int i = 0; i < 3; i++)
		cin >> peoples[i].X >> peoples[i].Y;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == i) continue;
			for (int k = 0; k < 3; k++) {
				if (k == i || k == j) continue;
				int tmp = get_dist(yumi, peoples[i]) + get_dist(peoples[i], peoples[j]) + get_dist(peoples[j], peoples[k]);
				res = min(res, tmp);
			}
		}
	}

	cout << res;
	return 0;
}