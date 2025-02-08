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
int N, K, M, L;
vector<int> gimbaps;
//=========================//

bool check(int x) {
	int cnt = 0;
	for (int gimbap : gimbaps)
		cnt += gimbap / x;
	return cnt >= M;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K >> M;

	for (int i = 0; i < N; i++) {
		cin >> L;
		if (L >= 2 * K) gimbaps.push_back(L - (2 * K));
		else if (L > K) gimbaps.push_back(L - K);
	}

	int lo = 0, hi = 1e9 + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}

	cout << (lo == 0 ? -1 : lo);
}