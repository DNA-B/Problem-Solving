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
int T = 1;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cout << fixed << setprecision(3);

	while (true) {
		double a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
			break;

		cout << "Triangle #" << T++ << '\n';

		if (c == -1) {
			double res = sqrt(a * a + b * b);
			cout << "c = " << res << '\n';
		}
		else if (a == -1) {
			if (c * c - b * b > 0)
				cout << "a = " << sqrt(c * c - b * b) << '\n';
			else
				cout << "Impossible." << '\n';
		}
		else if (b == -1) {
			if (c * c - a * a > 0)
				cout << "b = " << sqrt(c * c - a * a) << '\n';
			else
				cout << "Impossible." << '\n';
		}

		cout << '\n';
	}
}