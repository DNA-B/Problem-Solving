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
int T, N;
string s1, s2;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		int w = 0, b = 0;
		cin >> N >> s1 >> s2;

		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == 'W' && s1[i] != s2[i]) w++;
			else if (s1[i] == 'B' && s1[i] != s2[i]) b++;
		}

		cout << max(w, b) << '\n';
	}
}