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
int N, M, J, cnt = 0;
bool chk[15];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> J;
	fill(chk + 1, chk + (M + 1), true);

	int x;
	int lo = 1, hi = M;
	while (J--) {
		cin >> x;

		if (!chk[x]) {
			while (!chk[x]) {
				if (x < lo) {
					chk[hi--] = false;
					chk[--lo] = true;
					cnt++;
				}
				else if (x > hi) {
					chk[++hi] = true;
					chk[lo++] = false;
					cnt++;
				}
			}
		}
	}

	cout << cnt;
}