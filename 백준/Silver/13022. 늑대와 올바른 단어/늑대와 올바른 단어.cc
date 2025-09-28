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
int vis[55], word_cnt[4];
char WOLF[] = { 'w', 'o', 'l', 'f' };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		int idx = 0, cnt = 0;

		while (i < S.length()) {
			if (S[i] == WOLF[(idx + 1) % 4]) {
				idx = (idx + 1) % 4;
				if (idx == 0) {
					i--;
					break;
				}
			}

			if (S[i] == WOLF[idx]) {
				word_cnt[idx]++;
				cnt = max(cnt, word_cnt[idx]);
			}
			else { // wolf가 아님
				cout << 0;
				exit(0);
			}

			i++;
		}

		for (int j = 0; j < 4; j++) { // 문자가 n번 나오지 않음
			if (word_cnt[j] != cnt) {
				cout << 0;
				exit(0);
			}
		}

		fill(word_cnt, word_cnt + 4, 0);
	}

	cout << 1;
}