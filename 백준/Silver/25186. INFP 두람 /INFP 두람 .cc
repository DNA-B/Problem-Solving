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
int N;
ll total = 0, mx = 0;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	ll x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		total += x;
		mx = max(mx, x);
	}

	if (N == 1 && mx == 1) {
		cout << "Happy";
		exit(0);
	}

	cout << (2 * mx > total ? "Unhappy" : "Happy");
}