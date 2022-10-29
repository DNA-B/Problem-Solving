#include <bits/stdc++.h>

using namespace std;

vector<int> v[1001];
int vis[1001];

int n, m;
int cnt = 0;

void dfs(int s)
{
    if (vis[s] == 1)
        return;

    vis[s] = 1;

    for (int i = 0; i < v[s].size(); i++)
    {
        if (vis[v[s][i]] == 0)
            dfs(v[s][i]);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int s, e;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;

        // undirected graph
        v[s].push_back(e); 
        v[e].push_back(s);
        vis[s] = vis[e] = 0;
    }
        
    for (int i = 1; i < n + 1; i++)
    {
        if (!v[i].empty() && vis[i] == 0) // 연결 요소가 있고 아직 방문 안했다면 dfs
        {
            dfs(i);
            cnt++;
        }
    }

    for (int i = 1; i < n + 1; i++)
    { 
        // 정점들은 n 이하의 값들이니까 한 번씩 더 검사해주면 고립된 정점 처리 가능
        if (v[i].empty() && vis[i] == 0)
            cnt++;
    }

    cout << cnt;

    return 0;
}
