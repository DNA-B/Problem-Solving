#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include<unordered_set>
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
int T, K;
string W;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		vector<int> alp[26];
		int mx = -1, mn = INT_MAX;

		cin >> W >> K;

		for (int i = 0; i < W.size(); i++)
			alp[W[i] - 'a'].push_back(i);

		for (int i = 0; i < 26; i++) {
			int len = alp[i].size();

			if (len < K)
				continue;

			int dist = alp[i][K - 1] - alp[i][0] + 1;
			mx = max(dist, mx);
			mn = min(dist, mn);

			for (int j = K; j < len; j++) {
				dist = alp[i][j] - alp[i][j - K + 1] + 1;
				mx = max(dist, mx);
				mn = min(dist, mn);
			}
		}

		if (mx == -1 && mn == INT_MAX)
			cout << -1 << '\n';
		else
			cout << mn << ' ' << mx << '\n';
	}
}