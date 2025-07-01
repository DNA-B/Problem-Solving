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
int N;
string M;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	while (N--) {
		int cnt[26] = { 0, };
		bool flag = true;

		cin >> M;

		string tmp = "";
		for (int i = 0; i < M.size(); i++) {
			cnt[M[i] - 'A']++;
			if (cnt[M[i] - 'A'] == 3) {
				if (i == M.size() - 1 || M[i + 1] != M[i]) {
					flag = false;
					break;
				}
				else {
					cnt[M[i] - 'A'] = 0;
					i++;
				}
			}
		}

		if (flag)
			cout << "OK\n";
		else
			cout << "FAKE\n";
	}
}