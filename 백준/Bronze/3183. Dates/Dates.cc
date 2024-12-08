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
int M, D, Y;
//=========================//

bool is_leaf() {
	if (Y % 400 == 0)
		return true;
	else if (Y % 4 == 0 && Y % 100 != 0)
		return true;
	else
		return false;
}

bool check() {
	if (D == 0 || M == 0 || Y == 0) return false;
	if (D > 31 || M > 12) return false;
	if (D == 31 && (M == 4 || M == 6 || M == 9 || M == 11)) return false;
	if (D >= 30 && M == 2) return false;
	if (D == 29 && M == 2) return is_leaf();
	return true;
}
int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (cin >> D >> M >> Y) {
		if (D == 0 && M == 0 && Y == 0) break;
		if (check()) cout << "Valid\n";
		else cout << "Invalid\n";
	}
}