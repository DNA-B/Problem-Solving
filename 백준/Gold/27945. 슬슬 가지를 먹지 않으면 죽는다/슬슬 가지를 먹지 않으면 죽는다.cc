#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;
int cnt = 0, d = 1;
vector<int> p(100001, -1);
tuple<int, int, int> edge[500001];

int uf_find(int x)
{
	if (p[x] < 0)
		return x;

	return p[x] = uf_find(p[x]);
}

bool uf_union(int a, int b)
{
	a = uf_find(a);
	b = uf_find(b);

	if (a == b)
		return true;

	if (p[a] == p[b])
		p[a]--;

	if (p[a] < p[b])
		p[b] = a;
	else
		p[a] = b;

	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int a, b, cost, i = 0; i < M; i++)
	{
		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
	}

	sort(edge, edge + M);

	for (int a, b, cost, i = 0; i < M; i++)
	{
		tie(cost, a, b) = edge[i];

		if (cost != d) // 해당 날에 가게 문을 안 여는 상태
			break;
		if (uf_union(a, b))
			continue;

		d++;

		if (d == N)
			break;
	}

	cout << d;

	return 0;
}