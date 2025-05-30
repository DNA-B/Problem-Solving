#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int T, N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;
	while (T--) {
		cin >> N;

		int x, odd = 0, even = 0;
		while (N--) {
			cin >> x;
			(x & 1) ? odd++ : even++;
		}

		if (even > odd)
			swap(even, odd);

		if (odd % 2 && odd != even)
			cout << "amsminn";
		else
			cout << "heeda0528";
		cout << '\n';
	}
}