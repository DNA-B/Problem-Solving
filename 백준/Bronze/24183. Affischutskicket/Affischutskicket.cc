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
int c4, a3, a4;
const double C4 = (229 * 324) / 1000000.0;
const double A3 = (297 * 420) / 1000000.0;
const double A4 = (210 * 297) / 1000000.0;
//=========================//


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> c4 >> a3 >> a4;
	cout << fixed << setprecision(6);
	cout << (2 * c4 * C4) + (2 * a3 * A3) + (a4 * A4);
}