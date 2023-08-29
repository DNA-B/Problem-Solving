#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
vector<int> v[5001];
long long dist[5001][5001];
long long vis[5001];
long long ans = 0;

void bfs(int n, long long cur)
{
    ans = max(ans, cur);

    for (int i = 0; i < v[n].size(); i++)
    {
        if (vis[v[n][i]] != -1)
            continue;

        vis[v[n][i]] = 1;
        bfs(v[n][i], cur + dist[n][v[n][i]]);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    fill(vis, vis + 5001, -1);

    for (int i = 0; i < N - 1; i++)
    {
        int a, b, c;
        
        cin >> a >> b >> c;

        v[a].push_back(b);
        dist[a][b] = c;
        v[b].push_back(a);
        dist[b][a] = c;
    }
    
    vis[1] = 0;
    bfs(1, 0);
    cout << ans;

    return 0;
}