#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, M;
int time_table[100001];
int parent[100001];
int ans = 0;

void init_parent(int n)
{
    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int Find(int n)
{
    if (parent[n] == n)
        return n;

    return parent[n] = Find(parent[n]);
}

void Union(int a, int b)
{
    int x = Find(a);
    int y = Find(b);

    if (x == y)
        return;
    else if (x < y)
        parent[x] = y;
    else
        parent[y] = x;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    init_parent(N);
    for (int i = 0; i < M; i++)
    {
        int u, v;

        cin >> u >> v;
        Union(u, v);
    }

    for (int i = 0; i < N; i++)
        cin >> time_table[i];

    for (int i = 1; i < N; i++)
    {
        if (Find(time_table[i - 1]) != Find(time_table[i]))
            ans++;
    }

    cout << ans;

    return 0;
}
