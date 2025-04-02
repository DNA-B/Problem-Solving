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
int N, mn = INT_MAX;
int hills[1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> hills[i];

	for (int lo = 0; lo <= 83; lo++) {
		int hi = lo + 17;
		int cost = 0;

		for (int i = 0; i < N; i++) {
			if (hills[i] < lo)
				cost += (lo - hills[i]) * (lo - hills[i]);
			else if (hills[i] > hi)
				cost += (hills[i] - hi) * (hills[i] - hi);
		}

		mn = min(mn, cost);
	}

	cout << mn << '\n';
}