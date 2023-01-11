#include <bits/stdc++.h>

using namespace std;

int n, m;
int is_linked;
int a, b, u, v;
vector<int> parent(201);

int getParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = getParent(parent[x]);
}

void unionParent(int u, int v)
{
    u = getParent(u);
    v = getParent(v);

    if (u ==  v)
        return;

    parent[u] = v;
    getParent(u);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    parent.resize(n + 1);

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> is_linked;
            if (is_linked == 1)
                unionParent(i, j);
        }
    }

    cin >> u;

    for (int i = 0; i < m - 1; i++)
    {
        cin >> v;

        if (getParent(u) != getParent(v))
        {
            cout << "NO";
            return 0;
        }
        else
        {
            u = v;
        }
    }

    cout << "YES";

    return 0;
}