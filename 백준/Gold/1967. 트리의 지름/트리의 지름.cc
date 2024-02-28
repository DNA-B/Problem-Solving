#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> tree[10001]; // <노드 번호, 가중치>
int vis[10001];
int max_dist = INT_MIN, leaf_node;

void dfs(int cur_node, int cur_dist)
{
    vis[cur_node] = true;
    
	if (cur_dist > max_dist) // 한 지점에서 최대값이 갱신되었다는 것은 지름을 이루는 한 점을 찾았다는 것을 의미한다.
	{
		max_dist = cur_dist;
		leaf_node = cur_node;
	}

	for (int i = 0; i < tree[cur_node].size(); i++)
	{
		int next_node = tree[cur_node][i].first;
		int next_dist = tree[cur_node][i].second;

		if (!vis[next_node])
		{
			vis[next_node] = true;
			dfs(next_node, cur_dist + next_dist);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0, st, en, dist; i < N - 1; i++)
	{
		cin >> st >> en >> dist;

		tree[st].push_back({ en, dist });
		tree[en].push_back({ st, dist });
	}

	dfs(1, 0); // 지름을 이루는 한 지점 찾기
	fill(vis + 1, vis + (N + 1), false);
	dfs(leaf_node, 0); // 지름의 길이 구하기

	cout << max_dist;

	return 0;
}