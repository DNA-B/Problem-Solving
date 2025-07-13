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
vector<pair<int, int>> itvs;
map<int, int> m;
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
		itvs.push_back({ st, en });
		m[st]++;
		m[en + 1]--;
	}

	int cur = 0, mx = -1, moment = -1;
	for (auto [itv, cnt] : m) {
		cur += cnt;
		if (cur > mx) {
			mx = cur;
			moment = itv;
		}
	}

	vector<int> nodes;
	for (int i = 0; i < N; i++) {
		auto [st, en] = itvs[i];
		if (st <= moment && moment <= en)
			nodes.push_back(i + 1);
	}

	cout << mx << '\n';
	for (int node : nodes)
		cout << node << ' ';
}