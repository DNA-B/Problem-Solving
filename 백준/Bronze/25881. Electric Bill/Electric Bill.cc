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
int N, R1, R2;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> R1 >> R2 >> N;

	while (N--) {
		ll e;
		cin >> e;

		ll cost = 0;

		if (e <= 1000)
			cost = e * R1;
		else
			cost = (1000LL * R1) + (e - 1000) * R2;

		cout << e << " " << cost << "\n";
	}
}