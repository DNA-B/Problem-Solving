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
ll N, R, total = 0;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> R;

	ll D = N - R; 	// N - R = i * m;
	for (int i = 1; i <= sqrtl(D); i++) {
		if (D % i != 0)
			continue;

		ll a = i;
		ll b = D / i;

		if (i * i == D) { // 제곱근
			if (a > R)
				total += a;
		}
		else {
			if (a > R)
				total += a;
			if (b > R)
				total += b;
		}
	}

	cout << total;
}