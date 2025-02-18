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
int N, res = 0;
int cmp1[26], cmp2[26];
string S;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> S;

	for (char ch : S)
		cmp1[ch - 'A']++;

	string tmp;
	for (int i = 0; i < N - 1; i++) {
		int cnt = 0;
		int cmp2[26];

		copy(cmp1, cmp1 + 26, cmp2);
		cin >> tmp;

		for (char ch : tmp) {
			if (cmp2[ch - 'A']) {
				cmp2[ch - 'A']--;
				cnt++;
			}
		}

		if (S.size() == tmp.size()) {
			if (cnt == S.size() || cnt == S.size() - 1) res++;
		}
		else if (S.size() - 1 == tmp.size() && cnt == S.size() - 1) {
			res++;
		}
		else if (S.size() + 1 == tmp.size() && cnt == S.size()) {
			res++;
		}
	}

	cout << res;
}