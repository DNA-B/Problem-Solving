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
ll K, A, B;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> K >> A >> B;

	if (A > 0)
		cout << B / K - (A - 1) / K;
	else if (A == 0)
		cout << B / K + 1;
	else if (A < 0 && B < 0)
		cout << -A / K - (-B - 1) / K;
	else if (A < 0 && B == 0)
		cout << -A / K + 1;
	else
		cout << B / K + (-A / K) + 1;
}