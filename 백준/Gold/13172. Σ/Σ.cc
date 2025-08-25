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
const ll MOD = 1000000007;
int M, N, S;
//=========================//

ll fpow(ll a, ll b) {
	a %= MOD;
	if (b == 0)
		return 1;
	else if (b & 1)
		return a * fpow(a * a % MOD, b / 2) % MOD;
	else
		return fpow(a * a % MOD, b / 2) % MOD;
}

ll imod(ll x) {
	return fpow(x, MOD - 2) % MOD;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> M;

	ll res = 0;
	while (M--) {
		cin >> N >> S;
		res = (res + (S * imod(N) % MOD)) % MOD;
	}

	cout << res;
}