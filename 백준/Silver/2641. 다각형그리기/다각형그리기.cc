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
int N, M;
pair<int, int> dir[4] = { { 0, 1 }, { -1, 0 }, { 0, -1 }, { 1, 0 } };
vector<int> v;
vector<vector<int>> cands(105), res;
set<pair<int, int>> coords;
//=========================//

void make_coords() {
	int x = 50, y = 50;
	for (int i = 0; i < N; i++) {
		auto [dx, dy] = dir[v[i] - 1];
		x += dx, y += dy;
		coords.insert({ x, y });
	}
}

bool check(const vector<int>& cand) {
	for (auto [x, y] : coords) {
		set<pair<int, int>> tmp;
		for (int i = 0; i < N; i++) {
			auto [dx, dy] = dir[cand[i] - 1];
			x += dx, y += dy;
			tmp.insert({ x, y });
		}

		if (tmp == coords)
			return true;
	}

	return false;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}

	make_coords();

	cin >> M;

	for (int i = 0; i < M; i++) {
		for (int x, j = 0; j < N; j++) {
			cin >> x;
			cands[i].push_back(x);
		}

		if (check(cands[i]))
			res.push_back(cands[i]);
	}

	cout << res.size() << '\n';
	for (vector<int>& cand : res) {
		for (int x : cand)
			cout << x << ' ';
		cout << '\n';
	}
}