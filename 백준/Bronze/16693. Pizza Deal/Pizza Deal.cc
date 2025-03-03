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
double A1, P1, R1, P2;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> A1 >> P1 >> R1 >> P2;
	double tmp1 = A1 / P1;
	double tmp2 = R1 * R1 * PI / P2;
	cout << (tmp1 > tmp2 ? "Slice of pizza" : "Whole pizza");
}