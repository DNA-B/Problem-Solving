#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> vis;
int n, m, r;
int st, en;
int cnt = 1;

void dfs(int cur)
{
    vis[cur] = cnt;
    cnt++;

    for (int i = 0; i < graph[cur].size(); i++)
    {
        if (!vis[graph[cur][i]])
            dfs(graph[cur][i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r;
    graph.resize(n);
    vis.resize(n);

    for (int i = 0; i < m; i++)
    {
        cin >> st >> en;
        graph[st - 1].push_back(en - 1);
        graph[en - 1].push_back(st - 1);
    }

    for (int i = 0; i < graph.size(); i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(r - 1);

    for (int i = 0; i < n; i++)
        cout << vis[i] << "\n";

    return 0;
}