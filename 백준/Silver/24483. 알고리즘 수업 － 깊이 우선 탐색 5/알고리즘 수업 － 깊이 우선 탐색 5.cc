#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int N, M, R;
vector<int> v[200001];
bool vis[100001];
long long ans = 0, t = 1; // 깊이는 재귀로 되는데 방문 순서는 재귀로하면 동기화가 안되므로 전역 변수로 공유한다.

void dfs(int cur, int d)
{
	vis[cur] = true;
	ans += (d * t++);

	for (auto item : v[cur])
	{
		if (!vis[item])
			dfs(item, d + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> R;

	for (int st, en, i = 0; i < M; i++)
	{
		cin >> st >> en;

		v[st].push_back(en);
		v[en].push_back(st);
	}

	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	vis[R] = true;
	dfs(R, 0);

	cout << ans;

	return 0;
}