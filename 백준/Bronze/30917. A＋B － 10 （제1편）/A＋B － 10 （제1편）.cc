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
int A, B;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	int rep;
	for (int a = 1; a <= 9; a++) {
		cout << "? A " << a << endl;
		cin >> rep;

		if (rep == 1) {
			A = a;
			break;
		}
	}

	for (int b = 1; b <= 9; b++) {
		cout << "? B " << b << endl;
		cin >> rep;

		if (rep == 1) {
			B = b;
			cout << "! " << A + B;
			break;
		}
	}
}