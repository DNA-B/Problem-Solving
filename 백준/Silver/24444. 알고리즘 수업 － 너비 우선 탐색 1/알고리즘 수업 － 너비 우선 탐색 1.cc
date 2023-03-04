#include <bits/stdc++.h>

using namespace std;

int N, M, R;
int st, en;
int seq = 1;
vector<int> v[100001];
int vis[100001];
queue<int> q;

void bfs(int r) 
{
     vis[r] = seq++;
     q.push(r);

     while (!q.empty())
     {
         int cur = q.front();
         q.pop();

         for (int i = 0; i < v[cur].size(); i++)
         {
             if (vis[v[cur][i]] == 0)
             {
                 vis[v[cur][i]] = seq++;
                 q.push(v[cur][i]);
             }
         }
     }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++)
    {
        cin >> st >> en;
        v[st].push_back(en);
        v[en].push_back(st);
    }

    for (int i = 1; i <= N; i++)
        sort(v[i].begin(), v[i].end());

    bfs(R);

    for (int i = 1; i <= N; i++)
        cout << vis[i] << "\n";

    return 0;
}