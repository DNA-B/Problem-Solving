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
int X, Y;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	/*
	* 큰 값 먼저 -> 어차피 min이 0이니까
	* 작은 값 처리하고 거기서 감소되는 큰 값 더해주기 -> min(X, Y) / 10
	*/

	cin >> X >> Y;
	cout << (X + Y) + (min(X, Y) / 10);
}