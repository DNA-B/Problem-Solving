#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
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
int S, C;
ll arr[1000005];
//=========================//

bool check(ll x) {
	ll cnt = 0;
	for (int i = 0; i < S; i++)
		cnt += arr[i] / x;

	return cnt >= C;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S >> C;

	for (int i = 0; i < S; i++)
		cin >> arr[i];

	ll lo = 1, hi = 10'000'000'005;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;

		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}

	cout << accumulate(arr, arr + S, 0LL) - (lo * C);
}