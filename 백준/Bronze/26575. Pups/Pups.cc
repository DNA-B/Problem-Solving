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
double D, F, P, total;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	cout << fixed << setprecision(2);
	while (N--) {
		total = 0.0;
		cin >> D >> F >> P;
		total += D * F * P;
		cout << "$" << total << '\n';
	}
}