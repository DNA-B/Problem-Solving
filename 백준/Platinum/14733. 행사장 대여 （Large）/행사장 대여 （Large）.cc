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
int N;
int imos[6005][6005];
vector<int> X, Y;
vector<tuple<int, int, int, int>> v;
//=========================//

void proc_imos(int x, int y) {
	for (int i = x; i < X.size(); i++)
		for (int j = y; j < Y.size(); j++)
			imos[i][j] += imos[i - x][j - y];
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int x1, y1, d1, x2, y2, d2;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({ x1, y1, x2, y2 });
		X.push_back(x1); X.push_back(x2);
		Y.push_back(y1); Y.push_back(y2);
	}

	auto comp = [](vector<int>& tmp) { // 좌표 압축
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	};

	comp(X); comp(Y);

	auto trans = [](vector<int> tmp, int n) { // 매핑
		return lower_bound(tmp.begin(), tmp.end(), n) - tmp.begin();
	};

	for (auto [x1, y1, x2, y2] : v) {
		int rx1 = trans(X, x1), rx2 = trans(X, x2);
		int ry1 = trans(Y, y1), ry2 = trans(Y, y2);

		imos[rx1][ry1] += 1;
		imos[rx2][ry1] -= 1;
		imos[rx1][ry2] -= 1;
		imos[rx2][ry2] += 1;
	}

	proc_imos(1, 0); // X
	proc_imos(0, 1); // Y

	ll total = 0;
	for (int x = 0; x < X.size() - 1; x++) {
		for (int y = 0; y < Y.size() - 1; y++) {
			if (imos[x][y]) {
				ll x_len = X[x + 1] - X[x];
				ll y_len = Y[y + 1] - Y[y];
				total += x_len * y_len;
			}
		}
	}

	cout << total;
}