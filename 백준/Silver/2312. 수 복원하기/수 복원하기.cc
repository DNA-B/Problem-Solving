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

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	while (N--) {
		cin >> x;

		for (int i = 2; i <= x; i++) {
			int cnt = 0;

			while (x % i == 0) {
				cnt++;
				x /= i;
			}

			if (cnt != 0)
				cout << i << ' ' << cnt << '\n';
		}
	}

	return 0;
}