#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;
int n_edge = 0, cnt = 0, ans = 0;
vector<int> p(305, -1);
tuple<int, int, int> edge[100005];

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

	cin >> N;

	for (int cost, i = 1; i <= N; i++)
	{
		cin >> cost;
		edge[n_edge++] = { cost, i, N + 1 };
	}

	for (int i = 1; i <= N; i++)
	{
		for (int cost, j = 1; j <= N; j++)
		{
			cin >> cost;

			if (i >= j)
				continue;

			edge[n_edge++] = { cost, i, j };
		}
	}

	N++; // 가상의 정점 생성
	sort(edge, edge + n_edge);

	for (int a, b, cost, i = 0; i < n_edge; i++)
	{
		tie(cost, a, b) = edge[i];

		if (uf_union(a, b)) // 같은 그룹이면 continue;
			continue;

		ans += cost;
		cnt++;

		if (cnt == N - 1)
			break;
	}

	cout << ans;

	return 0;
}