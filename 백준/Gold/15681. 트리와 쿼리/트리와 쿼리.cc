#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, R, Q, st, en;
int subtree[100001];
vector<int> v[100001];
bool vis[100001];

int cnt_subtree(int cur)
{
	for (int i = 0; i < v[cur].size(); i++)
	{
		if (!vis[v[cur][i]])
		{
			vis[v[cur][i]] = true;
			subtree[cur] += cnt_subtree(v[cur][i]); // 자식 노드 카운트
		}
	}

	if (v[cur].empty()) // leaf Node
		return 1;
	else
		return subtree[cur];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> st >> en;
		v[st].push_back(en);
		v[en].push_back(st);
	}

	fill(subtree, subtree + (N + 1), 1); // 나 자신도 서브트리에 포함되므로 1
	vis[R] = true;
	cnt_subtree(R);

	for (int i = 0, x; i < Q; i++)
	{
		cin >> x;
		cout << subtree[x] << "\n";
	}

	return 0;
}