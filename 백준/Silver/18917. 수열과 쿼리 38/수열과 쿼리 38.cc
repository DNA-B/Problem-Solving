#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int M;
ll total = 0, v_xor = 0;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> M;

	int order, x;
	while (M--) {
		cin >> order;

		switch (order) {
			case 1:
				cin >> x;
				total += x;
				v_xor ^= x;
				break;
			case 2:
				cin >> x;
				total -= x;
				v_xor ^= x;
				break;
			case 3:
				cout << total << '\n';
				break;
			case 4:
				cout << v_xor << '\n';
				break;
		}
	}
}