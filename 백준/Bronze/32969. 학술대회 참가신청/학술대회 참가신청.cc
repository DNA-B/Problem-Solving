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
string s;
unordered_map<string, string> um = {
	{"social", "digital humanities"},{"history", "digital humanities"},
	{"language", "digital humanities"}, {"literacy", "digital humanities"},
	{"bigdata", "public bigdata"},{"public", "public bigdata"},
	{"society", "public bigdata"} };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	getline(cin, s);
	for (auto [word, track] : um) {
		if (s.find(word) != -1) {
			cout << track;
			break;
		}
	}
}