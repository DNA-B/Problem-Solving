#include <bits/stdc++.h>

using namespace std;

int N, M;
int st, en;
int ans = 0;
int vis[501];
int arr[501][501];
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

                if (vis[i] <= 2)
                    ans++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> M;

    for (int i = 1; i <= M; i++)
    {
        cin >> st >> en;
        arr[st][en] = 1;
        arr[en][st] = 1;
    }

    bfs(1);

    if (ans == 0)
        cout << 0;
    else
        cout << ans - 1;

    return 0;
}