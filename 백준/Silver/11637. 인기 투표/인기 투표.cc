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
int T, N;
int cand[15];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		cin >> N;

		int total = 0;
		for (int i = 1; i <= N; i++) {
			cin >> cand[i];
			total += cand[i];
		}

		int half = total / 2;
		int mx_idx = max_element(cand + 1, cand + (N + 1)) - cand;
		int mx = cand[mx_idx];
		int mx_cnt = count(cand + 1, cand + (N + 1), mx);

		if (mx_cnt >= 2)
			cout << "no winner\n";
		else if (mx > half)
			cout << "majority winner " << mx_idx << '\n';
		else if (mx <= half)
			cout << "minority winner " << mx_idx << '\n';
	}
}