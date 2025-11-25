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
int N, J, M;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int mn = INT_MAX, idx = INT_MAX;
	for (int tc = 1; tc <= N; tc++) {
		cin >> J >> M;
		int r = (J - 1) % (M + 1);

		if (mn > (J - r) / (M + 1) + 1) {
			mn = (J - r) / (M + 1) + 1;
			idx = tc;
		}
	}

	cout << idx << ' ' << 2 * mn;
}