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
int N, M, K;
int arr[1005];
vector<int> p(1005, -1);
deque<tuple<int, int, int>> adj;
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

	cin >> N >> M >> K;

	int x, y;
	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		adj.push_back({ i, x, y });
	}

	sort(adj.begin(), adj.end());

	while (K--) {
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

		cout << (cnt != N - 1 ? 0 : cost) << ' ';

		fill(p.begin(), p.end(), -1);
		adj.pop_front();
	}
}