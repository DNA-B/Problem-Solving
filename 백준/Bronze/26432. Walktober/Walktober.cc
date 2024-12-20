#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int T, M, N, P;
int part[1005][1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> N >> P;

		for (int p = 1; p <= M; p++) {
			for (int d = 0; d < N; d++)
				cin >> part[p][d];
		}

		int total = 0;
		for (int d = 0; d < N; d++) {
			int mx = -1;
			for (int p = 1; p <= M; p++)
				if (p != P) mx = max(mx, part[p][d]);
			total += max(0, mx - part[P][d]);
		}

		cout << "Case #" << tc << ": " << total << '\n';
	}
}