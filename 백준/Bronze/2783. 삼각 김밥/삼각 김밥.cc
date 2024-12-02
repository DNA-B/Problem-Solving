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
double X, Y, mn;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	cin >> X >> Y >> N;
	cout << fixed << setprecision(2);

	mn = (X / Y) * 1000.0;

	while (N--) {
		cin >> X >> Y;
		mn = min(mn, (X / Y) * 1000.0);
	}
	cout << mn;
}