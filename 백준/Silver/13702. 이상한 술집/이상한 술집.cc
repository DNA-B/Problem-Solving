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
int N, K;
int kettles[10005];
//=========================//

bool check(ll x) {
	int cnt = 0;
	for (int i = 0; i < N; i++)
		cnt += kettles[i] / x;
	return cnt >= K;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> kettles[i];

	ll lo = 0, hi = INT_MAX + 1LL;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;

		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}

	cout << lo << '\n';
}