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
int T;
string S = "";
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	if (T == 1) {
		ll A, B;
		cin >> A >> B;

		ll total = A + B;
		while (total) {
			S += (total % 26) + 'a';
			total /= 26;
		}

		for (int i = S.size(); i < 13; ++i)
			S += "a";

		cout << S;
	}
	else {
		cin >> S;

		ll total = 0, tmp = 1;
		for (int i = 0; i < 13; i++) {
			total += tmp * (S[i] - 'a');
			tmp *= 26;
		}

		cout << total;
	}
}