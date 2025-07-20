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
struct Planet {
	int id;
	int x, y, z;
};

int N;
vector<int> p(100005, -1);
vector<Planet> planets;
vector<tuple<int, int, int>> adj;
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

	cin >> N;

	int x, y, z;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> z;
		planets.push_back({ i, x, y, z });
	}

	for (int rep = 0; rep < 3; rep++) {
		sort(planets.begin(), planets.end(),
			[rep](const Planet& a, const Planet& b) {
			if (rep == 0) return a.x < b.x;
			if (rep == 1) return a.y < b.y;
			if (rep == 2) return a.z < b.z;
		});

		for (int i = 1; i < N; i++) { // 간선 생성
			Planet a = planets[i - 1];
			Planet b = planets[i];
			int cost = min({ abs(a.x - b.x), abs(a.y - b.y), abs(a.z - b.z) });
			adj.push_back({ cost, a.id, b.id });
		}
	}

	sort(adj.begin(), adj.end());

	int cnt = 0;
	ll total = 0;
	for (auto [cost, a, b] : adj) {
		if (!uf_union(a, b))
			continue;

		cnt++;
		total += cost;

		if (cnt == N - 1)
			break;
	}

	cout << total;
}