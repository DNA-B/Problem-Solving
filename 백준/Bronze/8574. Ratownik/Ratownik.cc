#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
int N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	ll k, x, y;
	cin >> N >> k >> x >> y;

	ll k_sq = k * k;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		ll xi, yi;
		cin >> xi >> yi;

		ll dist_sq = (x - xi) * (x - xi) + (y - yi) * (y - yi);

		if (dist_sq > k_sq)
			cnt++;
	}

	cout << cnt << endl;
}