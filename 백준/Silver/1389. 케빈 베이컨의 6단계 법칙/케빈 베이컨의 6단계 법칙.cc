#include <bits/stdc++.h>

using namespace std;

int N, M;
int a, b;
int ans[101];
vector<int> v[101];
int vis[101];
queue<int> q;

void bfs(int n)
{
    int q_size;

    vis[n] = 0;
    q.push(n);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int j = 0; j < v[cur].size(); j++)
        {
            if (vis[v[cur][j]] != -1)
                continue;

            q.push(v[cur][j]);
            vis[v[cur][j]] = vis[cur] + 1;
        }
    }
    
    for (int i = 1; i <= N; i++)
        ans[n] += vis[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        fill(vis, vis + 101, -1);
        bfs(i);
    }

    cout << min_element(ans + 1, ans + 1 + N) - ans;

    return 0;
}