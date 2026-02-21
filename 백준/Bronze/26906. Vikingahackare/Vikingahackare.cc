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
int T;
string S;
unordered_map<char, string> um;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	char ch;
	string bin;
	for (int i = 0; i < T; i++) {
		cin >> ch >> bin;
		um[ch] = bin;
	}

	cin >> S;

	string res = "";
	for (int i = 0; i < S.length(); i += 4) {
		string tmp = S.substr(i, 4);
		bool flag = false;

		for (auto [alp, bin] : um) {
			if (tmp == bin) {
				res += alp;
				flag = true;
				break;
			}
		}

		if (!flag)
			res += '?';
	}

	cout << res;
}