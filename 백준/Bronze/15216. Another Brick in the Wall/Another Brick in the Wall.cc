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
int h, w, n, cnt;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> h >> w >> n;

	int x, cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cur += x;

		if (cur == w) {
			cnt++;
			cur = 0;
		}
		if (cur > w) {
			cout << "NO";
			exit(0);
		}
		if (cnt == h) {
			cout << "YES";
			exit(0);
		}
	}

	cout << "NO";
}