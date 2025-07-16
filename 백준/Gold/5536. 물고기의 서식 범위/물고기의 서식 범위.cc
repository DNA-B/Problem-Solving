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
int imos[105][105][105];
vector<int> X, Y, D;
vector<tuple<int, int, int, int, int, int>> v;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	int x1, y1, d1, x2, y2, d2;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;
		v.push_back({ x1, y1, d1, x2, y2, d2 });
		X.push_back(x1); X.push_back(x2);
		Y.push_back(y1); Y.push_back(y2);
		D.push_back(d1); D.push_back(d2);
	}

	auto comp = [](vector<int>& tmp) { // 좌표 압축
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	};

	comp(X); comp(Y); comp(D);

	auto trans = [](vector<int> tmp, int n) { // 매핑
		return lower_bound(tmp.begin(), tmp.end(), n) - tmp.begin();
	};

	for (auto [x1, y1, d1, x2, y2, d2] : v) {
		int rx1 = trans(X, x1), rx2 = trans(X, x2);
		int ry1 = trans(Y, y1), ry2 = trans(Y, y2);
		int rd1 = trans(D, d1), rd2 = trans(D, d2);

		imos[rx1][ry1][rd1] += 1;
		imos[rx1][ry2][rd2] += 1;
		imos[rx2][ry1][rd2] += 1;
		imos[rx2][ry2][rd1] += 1;

		imos[rx2][ry1][rd1] -= 1;
		imos[rx1][ry2][rd1] -= 1;
		imos[rx1][ry1][rd2] -= 1;
		imos[rx2][ry2][rd2] -= 1;
	}

	for (int x = 1; x < X.size(); x++) // X
		for (int y = 0; y < Y.size(); y++)
			for (int d = 0; d < D.size(); d++)
				imos[x][y][d] += imos[x - 1][y][d];

	for (int x = 0; x < X.size(); x++) // Y
		for (int y = 1; y < Y.size(); y++)
			for (int d = 0; d < D.size(); d++)
				imos[x][y][d] += imos[x][y - 1][d];

	for (int x = 0; x < X.size(); x++) // D
		for (int y = 0; y < Y.size(); y++)
			for (int d = 1; d < D.size(); d++)
				imos[x][y][d] += imos[x][y][d - 1];


	ll total_volume = 0;
	for (int x = 0; x < X.size() - 1; x++) {
		for (int y = 0; y < Y.size() - 1; y++) {
			for (int d = 0; d < D.size() - 1; d++) {
				if (imos[x][y][d] >= K) {
					ll x_len = X[x + 1] - X[x];
					ll y_len = Y[y + 1] - Y[y];
					ll d_len = D[d + 1] - D[d];
					total_volume += x_len * y_len * d_len;
				}
			}
		}
	}

	cout << total_volume << '\n';
}