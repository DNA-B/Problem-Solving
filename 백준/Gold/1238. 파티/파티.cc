#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, X;
int u, v, t;
int ans = 0;
vector<pair<int, int>> adj[1001]; // {비용, 정점 번호}

int dijk(int st, int en)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int d[1001];
    fill(d, d + N + 1, INF);

    d[st] = 0;
    pq.push({ d[st],st });

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

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> t;
        adj[u].push_back({ t, v });
    }

    for (int i = 1; i <= N; i++)
        ans = max(ans, dijk(i, X) + dijk(X, i)); // 마을 갔다가 돌아오기.

    cout << ans;

    return 0;
}