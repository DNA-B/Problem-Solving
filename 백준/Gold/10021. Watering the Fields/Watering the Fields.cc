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
int N, C;
vector<int> p(2005, -1);
vector<tuple<int, int, int>> adj;
pair<int, int> arr[2005];
//=========================//

int uf_find(int x) {
	if (p[x] < 0)
		return x;
	return p[x] = uf_find(p[x]);
}

bool uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);

	if (a == b)
		return false;

	if (p[a] == p[b])
		p[a]--;
	if (p[a] < p[b])
		p[b] = a;
	else
		p[a] = b;

	return true;
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> C;

	int x, y;
	for (int i = 0; i < N; i++)
		cin >> arr[i].X >> arr[i].Y;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			int cost = pow(arr[i].X - arr[j].X, 2) + pow(arr[i].Y - arr[j].Y, 2);
			if (cost >= C) adj.push_back({ cost, i, j });
		}
	}

	sort(adj.begin(), adj.end());

	int cnt = 0;
	ll cost = 0;
	for (auto& [c, u, v] : adj) {
		if (!uf_union(u, v))
			continue;

		cost += c;
		cnt++;

		if (cnt == N - 1)
			break;
	}

	cout << (cnt != N - 1 ? -1 : cost);
}