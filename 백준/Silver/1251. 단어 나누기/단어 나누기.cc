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
set<string> dict;
//=========================//

string proc(string s1, string s2, string s3) {
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	reverse(s3.begin(), s3.end());
	return s1 + s2 + s3;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> S;

	string s1, s2, s3;
	for (int i = 1; i < S.size() - 1; i++) {
		for (int j = i + 1; j < S.size(); j++) {
			s1 = S.substr(0, i);
			s2 = S.substr(i, j - i);
			s3 = S.substr(j);
			dict.insert(proc(s1, s2, s3));
		}
	}
	cout << *dict.begin();
}