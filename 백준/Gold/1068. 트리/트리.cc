#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, parent, delete_node, root_node;
int ans = 0;
vector<int> tree[51];
bool vis[51];

void dfs(int cur)
{
	if (cur == delete_node) // root_node가 delete_node일 때
		return;

	for (int i = 0; i < tree[cur].size(); i++)
	{
		int next = tree[cur][i];

		if (!vis[next])
		{
			vis[next] = true;
			dfs(next);
		}
	}

	if (tree[cur].empty()) // leaf node라면 ans++ 
		ans++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> parent;

		if (parent == -1)
			root_node = i;
		else
			tree[parent].push_back(i);
	}

	cin >> delete_node;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < tree[i].size(); j++)
		{
			if (tree[i][j] == delete_node)
				tree[i].erase(tree[i].begin() + j);
		}

	}

	vis[root_node] = true;
	dfs(root_node);

	cout << ans;

	return 0;
}