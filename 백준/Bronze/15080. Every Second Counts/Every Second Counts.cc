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
int h1, m1, s1, h2, m2, s2;
char col;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> h1 >> col >> m1 >> col >> s1;
	cin >> h2 >> col >> m2 >> col >> s2;

	int total1 = (h1 * 60 * 60) + (m1 * 60) + s1;
	int total2 = (h2 * 60 * 60) + (m2 * 60) + s2;

	if (total2 < total1)
		total2 += 24 * 60 * 60;

	cout << total2 - total1;
}