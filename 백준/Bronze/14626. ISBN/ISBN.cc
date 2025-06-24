#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int idx = 0;
string S;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S;

	int total = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '*') {
			idx = i;
			continue;
		}

		if (i & 1)
			total += 3 * (S[i] - '0');
		else
			total += S[i] - '0';
	}

	for (int i = 0; i < 10; i++) {
		if (idx & 1) {
			if ((total + i * 3) % 10 == 0) {
				cout << i;
				break;
			}
		}
		else {
			if ((total + i) % 10 == 0) {
				cout << i;
				break;
			}
		}
	}
}