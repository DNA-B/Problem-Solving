#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
//#define X first
//#define Y second
//=========================//

//======= VARIABLEs =======//
int D, M;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	while (cin >> D >> M) {
		int arr[70005] = { 0, };

		for (int i = 0; i < D; i++)
			cin >> arr[i];

		ll mx = 0;
		int mn_price = arr[0];
		for (int i = 1; i < D; i++) {
			ll stock = M / mn_price;
			mx = max(mx, stock * (arr[i] - mn_price));
			mn_price = min(mn_price, arr[i]);
		}

		cout << mx << '\n';
	}
}