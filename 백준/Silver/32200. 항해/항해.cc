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
int N, X, Y;
int dine = 0, lef = 0;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> X >> Y;

	int a, m, l;
	while (N--) {
		cin >> a;
		m = a / X;
		dine += m;
		l = a % X;
		lef += max(l - (m * (Y - X)), 0);
	}

	cout << dine << '\n' << lef;
}