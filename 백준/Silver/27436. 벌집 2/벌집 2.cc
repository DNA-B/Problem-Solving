#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
ll N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	ll lo = 0, hi = 2e9;
	while (lo + 1 < hi) {
		ll mid = lo + (hi - lo) / 2;
		ll room = 3 * mid * (mid - 1) + 1;

		if (room < N)
			lo = mid;
		else
			hi = mid;
	}

	cout << hi;
}