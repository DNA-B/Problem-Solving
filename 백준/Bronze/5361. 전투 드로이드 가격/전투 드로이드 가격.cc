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
double prices[5] = { 350.34, 230.90, 190.55, 125.30, 180.90 };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;
	cout << fixed << setprecision(2);

	int bl, ec, vc, arm, leg;
	while (T--) {
		cin >> bl >> ec >> vc >> arm >> leg;
		cout << "$" << (bl * prices[0]) + (ec * prices[1]) + (vc * prices[2]) + (arm * prices[3]) + (leg * prices[4]) << '\n';
	}
}