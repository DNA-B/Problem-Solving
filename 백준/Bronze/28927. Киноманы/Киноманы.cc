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
int mx = 0, ml = 0;
int t1, e1, f1, t2, e2, f2;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> t1 >> e1 >> f1;
	cin >> t2 >> e2 >> f2;

	mx = (3 * t1) + (20 * e1) + (120 * f1);
	ml = (3 * t2) + (20 * e2) + (120 * f2);

	if (mx == ml)
		cout << "Draw";
	else if (mx > ml)
		cout << "Max";
	else
		cout << "Mel";
}