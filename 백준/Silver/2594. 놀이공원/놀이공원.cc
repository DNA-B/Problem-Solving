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
int mx = 0;
vector<pair<int, int>> attr;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int st, en, i = 0; i < N; i++) {
		cin >> st >> en;
		int st_h = st / 100;
		int en_h = en / 100;
		int st_m = st % 100;
		int en_m = en % 100;
		attr.push_back({ st_h * 60 + st_m, en_h * 60 + en_m });
	}

	sort(attr.begin(), attr.end());

	int cur = 10 * 60; // 개장
	for (int i = 0; i < attr.size(); i++) {
		auto [st, en] = attr[i];

		if (st - 10 > cur)
			mx = max(mx, (st - 10) - cur);
		if (en + 10 >= cur)
			cur = en + 10;
	}

	mx = max(mx, (22 * 60) - cur); // 폐장
	cout << mx;
}