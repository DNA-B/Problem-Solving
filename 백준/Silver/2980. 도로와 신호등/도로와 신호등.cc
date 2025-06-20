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
int N, L, D, R, G;
unordered_map<int, pair<int, int>> um;
//=========================//


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> D >> R >> G;
		um[D] = { R, G };
	}

	int l = 0, s = 0;
	while (l < L) {
		if (um.find(l) != um.end()) { // 신호등 위치에 도착
			auto [r, g] = um[l];
			if ((s % (r + g)) < r) {
				s += r - (s % (r + g));
				continue;
			}
		}

		s++;
		l++;
	}

	cout << s;
}