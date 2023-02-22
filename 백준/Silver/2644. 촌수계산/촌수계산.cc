#include <bits/stdc++.h>

using namespace std;

int N, M;
int want_x, want_y;
int st, en;
int vis[101];
int arr[101][101];
queue<int> q;

void bfs(int n)
{
    q.push(n);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= N; i++)
        {
            if (arr[cur][i] != 0 && !vis[i])
            {
                vis[i] = vis[cur] + 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> want_x >> want_y;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> st >> en;
        arr[st][en] = 1;
        arr[en][st] = 1;
    }

    bfs(want_x); // vis == 0이므로 굳이 vis[want_x]를 변경하지 않는다.
    
    if (vis[want_y] == 0)
        cout << -1;
    else
        cout << vis[want_y];

    return 0;
}