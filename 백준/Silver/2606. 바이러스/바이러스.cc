#include <bits/stdc++.h>

using namespace std;

int computer[101][101];
int vis[101];
queue<int> q;

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, e;
    int res = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        computer[s][e] = computer[e][s] = 1;
    }


    q.push(1);
    vis[1] = 1;

    while (!q.empty())
    {
        auto v = q.front();
        q.pop();

        for (int u = 1; u <= n; u++)
        {
            if (computer[v][u] == 1 && vis[u] == 0)
            {
                q.push(u);
                vis[u] = 1;
                res++;
            }
        }
    }


    cout << res;

    return 0;
}
