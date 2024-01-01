#include <bits/stdc++.h>

using namespace std;


int N, M, K, X;
vector<int> v[300001];
int vis[300001];
queue<int> q;
set<int> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++)
	{
		int st, en;

		cin >> st >> en;
		v[st].push_back(en);
	}

	fill(vis, vis + 300001, -1);
	vis[X] = 0;
	q.push(X);

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (vis[cur] == K)
			ans.insert(cur);

		for (int i = 0; i < v[cur].size(); i++)
		{
			if (vis[v[cur][i]] != -1)
				continue;

			vis[v[cur][i]] = vis[cur] + 1;
			q.push(v[cur][i]);
		}
	}

	if (ans.empty()) {
		cout << "-1";
	}
	else {
		for (auto item : ans)
			cout << item << "\n";
	}

	return 0;
}