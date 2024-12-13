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
int x1, x2;
int a, b, c, d, e;
//=========================//

int fomula(int x) {
	return ((a / 3) * pow(x, 3)) + ((b - d) / 2 * pow(x, 2)) + ((c - e) * x);
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> x1 >> x2;
	cin >> a >> b >> c >> d >> e;
	cout << fomula(x2) - fomula(x1);
}