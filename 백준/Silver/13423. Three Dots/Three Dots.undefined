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
vector<int> points;
//=========================//

int bsearch(int idx, int x1, int x2) {
	int lo = idx, hi = N;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (points[mid] - x2 == x2 - x1)
			return mid;
		else if (points[mid] - x2 > x2 - x1)
			hi = mid;
		else
			lo = mid;
	}

	return -1; // NONE
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		int cnt = 0;

		points.clear();
		cin >> N;

		for (int x, i = 0; i < N; i++) {
			cin >> x;
			points.push_back(x);
		}

		sort(points.begin(), points.end());

		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				int x1 = points[i];
				int x2 = points[j];

				if (bsearch(j, x1, x2) != -1)
					cnt++;
			}
		}
		cout << cnt << '\n';
	}
}