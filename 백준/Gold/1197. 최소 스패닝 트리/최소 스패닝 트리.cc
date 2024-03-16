#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int V, E;
int cnt = 0, ans = 0;
int p[10001];
tuple<int, int, int> edge[100001];

int uf_find(int x)
{
	if (p[x] == x)
		return x;

	return p[x] = uf_find(p[x]);
}

bool uf_union(int a, int b)
{
	a = uf_find(a);
	b = uf_find(b);

	if (a == b)
		return false;
	else
		p[max(a, b)] = min(a, b);

	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> V >> E;

	for (int a, b, cost, i = 0; i < E; i++)
	{
		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
	}

	sort(edge, edge + E);

	for (int i = 1; i <= V; i++)
		p[i] = i;

	for (int a, b, cost, i = 0; i < E; i++)
	{
		tie(cost, a, b) = edge[i];

		if (!uf_union(a, b))
			continue;

		ans += cost;
		cnt++;

		if (cnt == V - 1)
			break;
	}

	cout << ans;

	return 0;
}