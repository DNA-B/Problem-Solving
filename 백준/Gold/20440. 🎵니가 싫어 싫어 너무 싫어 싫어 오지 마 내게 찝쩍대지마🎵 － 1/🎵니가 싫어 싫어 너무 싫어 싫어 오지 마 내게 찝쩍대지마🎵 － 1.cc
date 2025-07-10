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
map<int, int> m;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	while (N--) {
		int x, y;
		cin >> x >> y;
		m[x]++;
		m[y]--;
	}

	int mx = -1, cur = 0;
	int st = -1, en = -1;
	for (auto [t, cnt] : m) {
		cur += cnt;
		if (mx < cur) {
			mx = cur;
			st = t;
			en = -1;
		}
		else if (mx > cur && en == -1) {
			en = t;
		}
	}

	cout << mx << '\n' << st << ' ' << en;
}