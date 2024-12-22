#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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
vector<pair<int, int>> edge, res;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int a, i = 0; i < M; i++) {
		cin >> a;
		edge.push_back({ a, a + 1 });
	}

	for (int i = 1; i <= N; i++) {
		int cur = i;
		for (auto [u, v] : edge) {
			if (u == cur) cur = v;
			else if (v == cur) cur = u;
		}
		res.push_back({ cur, i });
	}

	sort(res.begin(), res.end());
	for (auto [order, num] : res)
		cout << num << '\n';
}