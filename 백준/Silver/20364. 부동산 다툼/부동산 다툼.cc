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
int N, Q;
bool vis[1050005];
/***********************/

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> Q;

	int x;
	while (Q--) {
		int mn = INT_MAX, tmp;

		cin >> x;
		tmp = x;

		while (tmp != 1) {
			if (vis[tmp]) mn = min(mn, tmp);
			tmp >>= 1;
		}

		if (mn == INT_MAX) {
			vis[x] = true;
			cout << 0 << '\n';
		}
		else {
			cout << mn << "\n";
		}
	}

	return 0;
}