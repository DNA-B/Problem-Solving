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
int t1, t2, m1, m2;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> t1 >> m1 >> t2 >> m2;
	int total1 = t1 * 60 + m1;
	int total2 = t2 * 60 + m2;
	if (total1 > total2) total2 += 24 * 60;
	int total = total2 - total1;
	cout << total << ' ' << total / 30;
}