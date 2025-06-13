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
int Xs, Ys, Xe, Ye, dx, dy;
//=========================//

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int get_dist(int a, int b, int c, int d) {
	return ((a - c) * (a - c) + (b - d) * (b - d));
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> Xs >> Ys >> Xe >> Ye >> dx >> dy;

	int m = gcd(dx, dy);
	dx /= m;
	dy /= m;

	int mn_dist = get_dist(Xs, Ys, Xe, Ye);
	int x = Xe, y = Ye;

	while (true) {
		Xe += dx;
		Ye += dy;

		int currentDistance = get_dist(Xs, Ys, Xe, Ye);

		if (mn_dist <= currentDistance)
			break;

		mn_dist = currentDistance;
		x = Xe;
		y = Ye;
	}

	cout << x << ' ' << y << '\n';
}