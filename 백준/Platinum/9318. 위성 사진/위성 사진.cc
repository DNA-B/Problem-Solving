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
int T, N;
int imos[2005][2005];
vector<int> X, Y;
vector<tuple<int, int, int, int>> v;
//=========================//

void proc_imos(int x, int y) {
	for (int i = x; i < X.size(); i++) {
		for (int j = y; j < Y.size(); j++)
			imos[i][j] += imos[i - x][j - y];
	}
}


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		cin >> N;
		memset(imos, 0, sizeof(imos));

		int x1, y1, x2, y2;
		for (int i = 0; i < N; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			v.push_back({ x1, y1, x2, y2 });
			X.push_back(x1); X.push_back(x2);
			Y.push_back(y1); Y.push_back(y2);
		}

		auto comp = [](vector<int>& tmp) {
			sort(tmp.begin(), tmp.end());
			tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		};

		comp(X); comp(Y);

		auto trans = [](const vector<int>& tmp, int n) {
			return lower_bound(tmp.begin(), tmp.end(), n) - tmp.begin();
		};

		for (auto& [x1, y1, x2, y2] : v) {
			int rx1 = trans(X, x1), rx2 = trans(X, x2);
			int ry1 = trans(Y, y1), ry2 = trans(Y, y2);

			imos[rx1][ry1]++;
			imos[rx1][ry2]--;
			imos[rx2][ry1]--;
			imos[rx2][ry2]++;
		}

		proc_imos(1, 0);
		proc_imos(0, 1);

		ll total = 0;
		for (int i = 0; i < X.size() - 1; i++) {
			for (int j = 0; j < Y.size() - 1; j++) {
				if (imos[i][j]) {
					ll x_len = X[i + 1] - X[i];
					ll y_len = Y[j + 1] - Y[j];
					total += x_len * y_len;
				}
			}
		}

		cout << total << '\n';
		v.clear(); X.clear(); Y.clear();
	}
}