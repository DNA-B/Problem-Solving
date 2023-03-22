#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, st, en;
int u, v, w;
int d[1001]; // 거리
int pre[1001]; // 경로 저장
vector<int> ans;
int cur;
vector<pair<int, int>> adj[1001]; // {비용, 정점 번호}
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    fill(d, d + N + 1, INF);

    while (M--)
    {
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
    }

    cin >> st >> en;

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
            pre[nxt.second] = cur.second;
        }
    }

    cout << d[en] << "\n"; // 최소 비용
    
    cur = en;
    while (cur != st) // 경로 추출
    {
        ans.push_back(cur);
        cur = pre[cur];
    }
    ans.push_back(cur); // 시작점 포함
    
    cout << ans.size() << "\n"; // 경로 길이

    for (int i = ans.size() - 1; i >= 0; i--) // 도착점부터 경로 추출했으니까 거꾸로
        cout << ans[i] << " ";
  
    return 0;
}