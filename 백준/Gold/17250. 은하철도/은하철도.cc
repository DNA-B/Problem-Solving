#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M;
int planet[100001];
vector<int> p(100001, -1);

int uf_find(int x)
{
	if (p[x] < 0)
		return x;

	return p[x] = uf_find(p[x]);
}

int uf_union(int a, int b)
{
	a = uf_find(a);
	b = uf_find(b);

	if (a == b)
		return planet[a];

	if (p[a] == p[b])
		p[a]--;

	if (p[a] < p[b])
	{
		p[b] = a;
		planet[a] += planet[b];
		return planet[a];
	}
	else
	{
		p[a] = b;
		planet[b] += planet[a];
		return planet[b];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> planet[i];

	for (int a, b, i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << uf_union(a, b) << "\n";
	}

	return 0;
}