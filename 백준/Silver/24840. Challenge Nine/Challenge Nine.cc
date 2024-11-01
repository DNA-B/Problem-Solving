#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
//========= MACRO =========//
#define PI 3.1415926535897932
#define INT_INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int T;
string N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cout << "Case #" << tc << ": ";
		cin >> N;

		int sum = 0;
		for (char ch : N)
			sum += ch - '0';

		int need = (9 - sum % 9) % 9;
		if (need == 0) {
			cout << N[0] << '0' << N.substr(1) << '\n';
			continue;
		}

		int len = N.length();
		bool flag = false;
		for (int i = 0; i < len; ++i) {
			if (N[i] > (need + '0')) {
				cout << N.substr(0, i) << (char)(need + '0') << N.substr(i, len - i) << '\n';
				flag = true;
				break;
			}
		}

		if (!flag)
			cout << N << (char)(need + '0') << '\n';
	}
	return 0;
}