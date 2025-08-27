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
int T;
double cm, y, su, sa, f;
int b, gs, gc, w;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		const double BASE = 16.0;
		int res = 0, kneading = 0, cnt = INT_MAX;

		cin >> cm >> y >> su >> sa >> f;
		kneading = min({ cm / (8 / BASE), y / (8 / BASE), su / (4 / BASE), sa / (1 / BASE), f / (9 / BASE) });
		cin >> b >> gs >> gc >> w;

		res += min(kneading, b);
		kneading -= min(kneading, b);

		res += min(kneading, w / 10);
		kneading -= min(kneading, w / 10);

		res += min(kneading, gc / 25);
		kneading -= min(kneading, gc / 25);

		res += min(kneading, gs / 30);
		kneading -= min(kneading, gs / 30);

		cout << res << '\n';
	}
}