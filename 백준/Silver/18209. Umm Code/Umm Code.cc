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
string S, um;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	while (cin >> S) {
		bool flag = false;
		string tmp = "";
		for (char ch : S) {
			if (ch == 'u')
				tmp += '1';
			else if (ch == 'm')
				tmp += '0';
			else if (('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')) {
				flag = true;
				break;
			}
		}

		if (!flag)
			um += tmp;
	}

	for (int i = 0; i <= um.size(); i += 7) {
		string tmp = um.substr(i, 7);
		int total = 0, p = 6;
		for (char ch : tmp) {
			total |= (ch - '0') << p;
			p--;
		}

		if (total)
			cout << (char)total;
	}
}