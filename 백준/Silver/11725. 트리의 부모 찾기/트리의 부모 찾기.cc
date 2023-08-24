#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int N;
int parent[100001];
vector<int> tree[100001];

void solve(int n)
{
    for (int item : tree[n])
    {
        if (parent[item] != 0)
            continue;

        parent[item] = n;
        solve(item);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    parent[1] = 1;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    solve(1);

    for (int i = 2; i <= N; i++)
        cout << parent[i] << "\n";

    return 0;
}