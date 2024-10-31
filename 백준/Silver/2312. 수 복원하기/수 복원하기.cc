#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N, x;
//=========================//

void solve(int x) {
	map<int, int> um; // { num, cnt }

	while (x > 1) {
		for (int i = 2; i <= x; i++) {
			if (x % i == 0) {
				um[i]++;
				x /= i;
				break;
			}
		}
	}

	for (auto [num, cnt] : um)
		cout << num << ' ' << cnt << '\n';
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		cin >> x;
		solve(x);
	}

	return 0;
}