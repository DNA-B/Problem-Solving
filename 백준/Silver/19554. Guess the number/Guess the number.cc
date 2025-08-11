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
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int rep;
	int lo = 0, hi = N + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		cout << "? " << mid << '\n' << flush;
		cin >> rep;

		if (rep == 0) {
			cout << "= " << mid;
			exit(0);
		}

		if (rep == 1)
			hi = mid;
		else if (rep == -1)
			lo = mid;
	}

	cout << "? " << lo << '\n' << flush;
	cin >> rep;

	if (rep == 0)
		cout << "= " << lo;
	else
		cout << "= " << hi;
}