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
int N, S, R, cnt = 0;
set<int> s;
map<int, bool> m;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> S >> R;

	for (int x, i = 0; i < S; i++) {
		cin >> x;
		s.insert(x);
	}

	for (int x, i = 0; i < R; i++) {
		cin >> x;

		if (s.find(x) != s.end()) {
			s.erase(x);
			continue;
		}

		m[x] = true;
	}

	for (int boat : s) {
		if (m[boat - 1]) {
			m[boat - 1] = false;
			continue;
		}
		else if (m[boat + 1]) {
			m[boat + 1] = false;
			continue;
		}
		cnt++;
	}

	cout << cnt;
}