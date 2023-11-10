#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int T, N, M, K;
int time_table[1000001];
int parent[1000001];
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

    parent[max(x, y)] = min(x, y); // 작은 값을 부모로
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cout << "Scenario " << i << ":\n";

        cin >> N >> K;

        init_parent(N);
        for (int i = 0; i < K; i++)
        {
            int a, b;

            cin >> a >> b;
            Union(a, b);
        }

        cin >> M;

        for (int i = 0; i < M; i++)
        {
            int u, v;

            cin >> u >> v;

            if (Find(u) != Find(v))
                cout << "0\n";
            else
                cout << "1\n";
        }

        cout << "\n";
    }
    
    return 0;
}
