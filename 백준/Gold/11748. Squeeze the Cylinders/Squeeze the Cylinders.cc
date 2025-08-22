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
int N;
vector<double> R, X;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	double x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		R.push_back(x);
	}

	X.push_back(0.0);
	for (int i = 1; i < N; i++) {
		double mx = -1e18;
		for (int j = 0; j < i; j++) // (xi - xj)^2 + (ri - rj)^2 = (ri + rj)^2
			mx = max(mx, X[j] + 2.0 * sqrt(R[i] * R[j]));
		X.push_back(mx);
	}

	double mn_l = 1e18, mx_r = -1e18;
	for (int i = 0; i < N; i++) {
		mn_l = min(mn_l, X[i] - R[i]);
		mx_r = max(mx_r, X[i] + R[i]);
	}

	cout << fixed << setprecision(8) << (mx_r - mn_l);
}