#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M, st, en, di;
vector<pair<int, int>> v[1001]; // <노드 번호, 거리>
bool vis[1001];
int ans = 0;

void cal_dist(int cur_node, int cur_dist)
{
	if (cur_node == en)
		ans = cur_dist;

	for (int i = 0; i < v[cur_node].size(); i++)
	{
		int next_node = v[cur_node][i].first;
		int next_dist = v[cur_node][i].second;

		if (!vis[next_node])
		{
			vis[next_node] = true;
			cal_dist(next_node, cur_dist + next_dist);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> st >> en >> di; // 노드 1, 노드 2, 거리
		v[st].push_back({ en, di });
		v[en].push_back({ st, di });
	}

	for (int i = 0; i < M; i++)
	{
		fill(vis, vis + (N + 1), false);

		cin >> st >> en;

		ans = 0;
		vis[st] = 1;
		cal_dist(st, 0);

		cout << ans << "\n";
	}

	return 0;
}