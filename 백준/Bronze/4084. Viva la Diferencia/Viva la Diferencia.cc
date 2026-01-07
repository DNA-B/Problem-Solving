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

//=========================//

bool check(vector<ll>& v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != v[(i + 1) % v.size()])
			return false;
	}
	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	ll a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if (!a && !b && !c && !d)
			break;

		int cnt = 0;
		vector<ll> v = { a, b, c, d };
		vector<ll> newv = v;
		while (!check(v)) {
			for (int i = 0; i < v.size(); i++)
				newv[i] = abs(v[i] - v[(i + 1) % v.size()]);
			v = newv;
			cnt++;
		}

		cout << cnt << '\n';
	}
}