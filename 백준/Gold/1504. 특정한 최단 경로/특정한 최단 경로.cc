#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, E;
int a, b, c;
int v1, v2;
long long ans = 0;
vector<pair<int, int>> adj[801];

long long dijk(int st, int en)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    int d[801];
    fill(d, d + N + 1, INF);

    d[st] = 0;
    pq.push({ d[st], st});

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.second] != cur.first)
            continue;

        for (auto nxt : adj[cur.second])
        {
            if (d[nxt.second] <= d[cur.second] + nxt.first)
                continue;

            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({ d[nxt.second], nxt.second });
        }
    }

    return d[en];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }

    cin >> v1 >> v2;

    ans = dijk(1, v1) + dijk(v1, v2) + dijk(v2, N);
    ans = min(ans, dijk(1, v2) + dijk(v2, v1) + dijk(v1, N));

    if (ans >= INF)
        cout << -1;
    else
        cout << ans;

    return 0;
}