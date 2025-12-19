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
const int DELTA = 1422;
int N;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	while (cin >> N) {
		if (N == 0)
			break;

		vector<bool> cs(1500, false);

		for (int x, i = 0; i < N; i++) {
			cin >> x;
			cs[x] = true;
		}

		bool flag = true;
		int cur = 200;
		for (int i = 0; i <= DELTA; i++) {
			if (cur < 0) {
				flag = false;
				break;
			}

			cur--;

			if (cs[i])
				cur = 200;
		}

		if (!flag) {
			cout << "IMPOSSIBLE\n";
			continue;
		}

		for (int i = DELTA; i >= 0; i--) {
			if (cur < 0) {
				flag = false;
				break;
			}

			cur--;

			if (cs[i])
				cur = 200;
		}

		cout << (!flag ? "IMPOSSIBLE" : "POSSIBLE") << "\n";
	}
}