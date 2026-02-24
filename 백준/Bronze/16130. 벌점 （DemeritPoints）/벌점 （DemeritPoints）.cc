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
int N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	while (N--) {
		string info;

		cin >> info;

		int total = 0, cnt = 0;
		string suffix = "";
		for (char ch : info) {
			int pre = total / 10;
			total += ('A' <= ch && ch <= 'Z' ? (ch - 'A') + 10 : (ch - '0'));
			int cur = total / 10;

			if (cur == 4) {
				suffix = "(weapon)";
				break;
			}
			else if (cur > 4) {
				suffix = "(09)";
				break;
			}
			else if (pre != cur) {
				cnt += cur;
			}
		}

		cout << cnt << suffix << '\n';
	}
}