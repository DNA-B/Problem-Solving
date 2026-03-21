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
int A, C, E, x, y, z;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> A >> C >> E >> x >> y >> z;

	if (x == A && y == C && z == E)
		cout << "A";
	else if (((A + 1) / 2 <= x && x < A) && y == C && z == E)
		cout << "B";
	else if (y == C && z == E)
		cout << "C";
	else if (((C + 1) / 2 <= y && y < C) && z == E)
		cout << "D";
	else if (z == E)
		cout << "E";
}