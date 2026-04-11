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
int T;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		int n;

		cin >> n;
		cout << "Denominations: ";

		int x, prev = -1;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			cin >> x;
			cout << x << ' ';
			if (prev != -1 && x < prev * 2)
				flag = false;
			prev = x;
		}

		cout << '\n' << (flag ? "Good coin denominations!" : "Bad coin denominations!") << "\n\n";
	}
}