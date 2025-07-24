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
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		int cnt = 0;
		string S;

		cin >> S;

		while (S != "6174") {
			sort(S.begin(), S.end(), greater<>());
			string mx = S;
			sort(S.begin(), S.end());
			string mn = S;
			S = to_string(stoi(mx) - stoi(mn));
			while (S.length() < 4) S = "0" + S;
			cnt++;
		}

		cout << cnt << '\n';
	}
}