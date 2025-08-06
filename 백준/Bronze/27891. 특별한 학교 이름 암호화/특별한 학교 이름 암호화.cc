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
vector<pair<string, string>> schools = {
	{"NLCS", "northlondo"}, {"BHA","branksomeh"},
	{"KIS", "koreainter"}, {"SJA", "stjohnsbur" } };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S;

	for (int i = 0; i < 100; i++) {
		for (char& ch : S)
			ch = (((ch - 'a') + 26 - 1) % 26) + 'a';

		for (auto [abb, name] : schools) {
			if (S == name) {
				cout << abb;
				exit(0);
			}
		}
	}
}