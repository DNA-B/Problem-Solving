#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int M, N;
vector<int> p(200001, -1);
tuple<int, int, int> edge[200001];

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
		return false;

	if (p[a] == p[b])
		p[a]--;

	if (p[a] < p[b])
		p[b] = a;
	else
		p[a] = b;

	return true;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	while (true)
	{
		int total_cost = 0, sub_cost = 0, cnt = 0;

		cin >> M >> N;

		if (M == 0 && N == 0)
			break;

		fill(p.begin(), p.begin() + M, -1);
		fill(edge, edge + M, make_tuple(0, 0, 0));

		for (int x, y, z, i = 0; i < N; i++)
		{
			cin >> x >> y >> z;

			total_cost += z;
			edge[i] = { z, x, y };
		}

		sort(edge, edge + N);

		for (int x, y, z, i = 0; i < N; i++)
		{
			tie(z, x, y) = edge[i];

			if (!uf_union(x, y))
				continue;

			sub_cost += z;
			cnt++;

			if (cnt == M - 1)
				break;
		}

		cout << total_cost - sub_cost << "\n";
	}


	return 0;
}