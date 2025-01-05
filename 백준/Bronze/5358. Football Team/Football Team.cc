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
string S;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	while (getline(cin, S)) {
		for (char& ch : S) {
			if (ch == 'i') ch = 'e';
			else if (ch == 'e') ch = 'i';
			else if (ch == 'I') ch = 'E';
			else if (ch == 'E')	ch = 'I';
		}
		cout << S << '\n';
	}
}