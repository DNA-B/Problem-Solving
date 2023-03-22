#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int V, E, st;
int u, v, w;
int d[20005]; // 거리
vector<pair<int, int>> adj[20005]; // {비용, 정점 번호}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E >> st;
    fill(d, d + V + 1, INF);

    while (E--)
    {
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
    }

    d[st] = 0;
    pq.push({ d[st],st });

    while (!pq.empty()) 
    {
        auto cur = pq.top(); 
        pq.pop();   

        if (d[cur.second] != cur.first) // 거리가 d에 있는 값과 다를 경우 넘어감
            continue;

        for (auto nxt : adj[cur.second]) 
        {
            if (d[nxt.second] <= d[cur.second] + nxt.first) // 이미 있던 값이 더 작을 경우 pass
                continue;

            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({ d[nxt.second],nxt.second });
        }
    }

    for (int i = 1; i <= V; i++) 
    {
        if (d[i] == INF) 
            cout << "INF\n";
        else 
            cout << d[i] << "\n";
    }

    return 0;
}