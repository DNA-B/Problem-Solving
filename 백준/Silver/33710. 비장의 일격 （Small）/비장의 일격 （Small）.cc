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
int N, K;
string S;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K >> S;

	int mn = N;
	for (int i = 0; i < N - 1; i++) {
		if (S[i] != 'X') { // 첫번째 쌍 탐색
			for (int j = i + 1; j < N; j++) {
				if (S[j] == S[i]) {
					string tmp1 = S;
					tmp1.erase(i, j - i + 1);
					mn = min(mn, (int)tmp1.size());

					for (int k = 0; k < (int)tmp1.size() - 1; k++) {
						if (tmp1[k] != 'X') { // 두번째 쌍 탐색
							for (int l = k + 1; l < (int)tmp1.size(); l++) {
								if (tmp1[l] == tmp1[k]) {
									string tmp2 = tmp1;
									tmp2.erase(k, l - k + 1);
									mn = min(mn, (int)tmp2.size());
								}
							}
						}
					}
				}
			}
		}
	}

	cout << mn;
}