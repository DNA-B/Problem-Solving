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
int cnt = 0;
string S, E, Q;
string t, name;
unordered_map<string, int> m;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S >> E >> Q;

	while (cin >> t >> name) {
		if (t <= S)
			m[name] = 1;
		else if ((E <= t && t <= Q) && m[name]) {
			m[name] = 0;
			cnt++;
		}
	}

	cout << cnt;
}