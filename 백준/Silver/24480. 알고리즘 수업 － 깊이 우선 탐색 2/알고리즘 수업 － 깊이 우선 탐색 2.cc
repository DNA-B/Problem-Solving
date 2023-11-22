#include <bits/stdc++.h>

using namespace std;

int N, M, R;
vector<int> v[100001];
int vis[100001];
int cnt = 1;

void dfs(int r)
{
    vis[r] = cnt++;

    for (auto item : v[r])
        if (!vis[item])
            dfs(item);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++)
    {
        int st, en;

        cin >> st >> en;
        v[st].emplace_back(en);
        v[en].emplace_back(st);
    }

    for (int i = 1; i <= N; i++)
        sort(v[i].begin(), v[i].end(), greater<>());

    dfs(R);

    for (int i = 1; i <= N; i++)
        cout << vis[i] << "\n";

    return 0;
}
