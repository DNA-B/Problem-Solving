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
string VY, ABCD, RB;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	while (cin >> VY >> ABCD >> RB) {
		int cnt = 0;

		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j < ABCD.length() - 1; j++) {
				if (ABCD[j] - '0' == i && ABCD[j + 1] - '0' == i) {
					if (cnt > 0) cout << " and ";
					cout << i << ' ' << i << " glued";
					cnt++;
					break;
				}
			}
		}

		if (cnt > 0)
			cout << '\n';
	}
}