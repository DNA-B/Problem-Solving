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
ll M, N, S;
vector<pair<ll, ll>> dices;
//=========================//

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll fpow(ll n, ll m) {
	ll ret = 1;
	while (m) {
		if (m & 1) ret = ret * n % MOD;
		m /= 2;
		n = n * n % MOD;
	}
	return ret;
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
		ll g = gcd(N, S);
		N /= g, S /= g;
		res = (res + (S * imod(N) % MOD)) % MOD;
	}

	cout << res;
}