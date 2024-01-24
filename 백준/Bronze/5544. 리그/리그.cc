#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;
int team[101], team_rank[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	fill(team_rank, team_rank + (N + 1), 1);

	for (int i = 0; i < (N * (N - 1)) / 2; i++)
	{
		int a, b, c, d;

		cin >> a >> b >> c >> d;

		if (c == d)
		{
			team[a] += 1;
			team[b] += 1;
		}
		else if (c > d)
		{
			team[a] += 3;
			team[b] += 0;
		}
		else
		{
			team[a] += 0;
			team[b] += 3;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				continue;

			if (team[i] < team[j])
				team_rank[i]++;
		}
	}

	for (int i = 1; i <= N; i++)
		cout << team_rank[i] << '\n';

	return 0;
}