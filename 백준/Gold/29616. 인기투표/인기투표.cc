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
int N, P;
vector<ll> pre, cur;
//=========================//

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> P;

	ll x;
	cin >> x;
	pre.push_back(x);

	ll pre_gcd = x, pre_total = 0;
	for (int i = 0; i < N - 1; i++) {
		cin >> x;
		pre.push_back(x);
		pre_gcd = gcd(pre_gcd, x);
	}

	for (int i = 0; i < N; i++)
		pre_total += pre[i] / pre_gcd;

	cin >> x;
	cur.push_back(x);

	ll cur_gcd = x, cur_total = 0;
	for (int i = 0; i < N - 1; i++) {
		cin >> x;
		cur.push_back(x);
		cur_gcd = gcd(cur_gcd, x);
	}

	double mx_ratio = 0.0;
	for (int i = 0; i < N; i++) {
		ll pre_votes = pre[i] / pre_gcd;
		ll cur_votes = cur[i] / cur_gcd;
		mx_ratio = max(mx_ratio, (double)pre_votes / cur_votes);
	}

	ll ratio = ceil(mx_ratio);

	for (int i = 0; i < N; i++)
		cur_total += (cur[i] / cur_gcd);

	cout << pre_total << ' ' << ratio * cur_total;
}