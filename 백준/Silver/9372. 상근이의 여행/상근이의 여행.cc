#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int T, N, M;
vector<vector<int>> v;
bool vis[1001];
int cnt = 0;

void dfs(int cur)
{
	if (count(vis + 1, vis + (N + 1), true) == N)
		return;

	for (int i = 0; i < v[cur].size(); i++)
	{
		if (!vis[v[cur][i]]) // false
		{
			cnt++;
			vis[v[cur][i]] = true;
			dfs(v[cur][i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--)
	{
		int a, b;

		cin >> N >> M;

		v.resize(N + 1);
		fill(vis + 1, vis + N + 1, false);
		cnt = 0;

		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1; i <= N; i++)
		{
			if (!v[i].empty() && !vis[i])
			{
				vis[i] = true;
				dfs(i);
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}