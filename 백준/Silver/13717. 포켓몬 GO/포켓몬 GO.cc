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
#define ull unsigned long long
#define X first
#define Y second
/***********************/

/****** VARIABLEs ******/
int N, mx = -1, res = 0;
string mx_po;
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		int k, m, cnt = 0;
		string name;

		cin >> name >> k >> m;

		while (m >= k) {
			int tmp = m / k;
			cnt += tmp;
			m -= tmp * (k - 2);
		}

		if (cnt > mx) {
			mx = cnt;
			mx_po = name;
		}
		res += cnt;
	}

	cout << res << '\n' << mx_po;
	return 0;
}