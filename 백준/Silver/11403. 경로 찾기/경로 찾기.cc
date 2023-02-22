#include <bits/stdc++.h>

using namespace std;

int n, x;
int vis[101];
vector<int> v[101];


void dfs(int n)
{
    for (int i = 0; i < v[n].size(); i++)
    {
        if (!vis[v[n][i]])
        {
            vis[v[n][i]] = true;
            dfs(v[n][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if (x == 1)
                v[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        fill(vis, vis + 101, 0);
        dfs(i);

        for (int j = 0; j < n; j++)
            cout << vis[j]<<" ";
        cout << "\n";
    }

    return 0;
}