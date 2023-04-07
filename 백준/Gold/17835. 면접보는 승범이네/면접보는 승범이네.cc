#include<bits/stdc++.h>

using namespace std;

const int MX = 100'002;
const long long INF = 0x7f7f7f7f7f7f;

int N, M, K;
int u, v, c;
int k;
long long d[100001];
vector<pair<long long, long long>> adj[100001];
priority_queue<pair<long long, long long>,
    vector<pair<long long, long long>>,
    greater<pair<long long, long long>>> pq;

void dijk()
{
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
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    fill(d + 1, d + N + 1, INF);

    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v >> c;
        adj[v].push_back({ c, u }); // 면접장 -> 마을 (역방향)
    }

    for (int i = 1; i <= K; i++)
    {
        cin >> k;
        d[k] = 0;
        pq.push({ d[k], k });
    }

    dijk();

    int idx = max_element(d + 1, d + N + 1) - d;
    cout << idx << "\n";
    cout << d[idx];

    return 0;
}