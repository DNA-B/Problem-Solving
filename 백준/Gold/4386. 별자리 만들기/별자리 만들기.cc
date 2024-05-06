#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 101
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, cnt = 0;
double ans = 0;
vector<int> p(BOUND, -1);
vector<pair<double, double>> star;
vector<tuple<double, int, int>> edge; // {cost, st, en}
/***********************/

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
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		double a, b;

		cin >> a >> b;
		star.push_back({ a, b });
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			double x_cost, y_cost, cost;

			if (i == j)
				continue;

			x_cost = pow(star[i].X - star[j].X, 2);
			y_cost = pow(star[i].Y - star[j].Y, 2);
			cost = sqrt(x_cost + y_cost);

			edge.push_back({ cost, i, j });
		}
	}

	sort(edge.begin(), edge.end()); // cost 오름차순으로 정렬

	for (int i = 0; i < edge.size(); i++) {
		double cost;
		int a, b;

		tie(cost, a, b) = edge[i];

		if (!uf_union(a, b))
			continue;

		ans += cost;
		cnt++;

		if (cnt == N - 1)
			break;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;

	return 0;
}