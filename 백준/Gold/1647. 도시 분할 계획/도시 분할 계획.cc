#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;
int cnt = 0, ans = 0;
vector<int> p(100001, -1);
tuple<int, int, int> edge[1000001];

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

	if (N == 2) // 집이 2개만 있으면 두 개로 나누고 끝내면 된다.
	{
		cout << 0;
		return 0;
	}

	for (int a, b, cost, i = 0; i < M; i++)
	{
		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
	}

	sort(edge, edge + M);

	for (int a, b, cost, i = 0; i < M; i++)
	{
		tie(cost, a, b) = edge[i];

		if (uf_union(a, b))
			continue;

		cnt++;
		ans += cost;

		if (cnt == N - 2) // 마을을 두 개로 나눠야 한다 -> 마지막 하나의 노드만 남기고 MST를 구성하면 최저 비용
			break;
	}

	cout << ans;

	return 0;
}