#include <bits/stdc++.h>

using namespace std;

int vis[1000002];
int ud[2] = {}; // 상하좌우
queue<int> q;

int main() // 1층부터 시작하는 것 주의, 1차원 BFS
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d;
    int count = 0;

    cin >> f >> s >> g >> u >> d;

    fill(vis + 1, vis + f + 1, -1);
    ud[0] = u;
    ud[1] = -d;
    vis[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 2; dir++)
        {
            int nud = cur + ud[dir]; // 방향 설정

            if (nud < 1 || nud > f)
                continue; // 범위 밖일 경우
            if (vis[nud] != -1)
                continue;

            vis[nud] = vis[cur] + 1;
            q.push(nud);
        }
    }

    if (vis[g] == -1)
        cout << "use the stairs";
    else
        cout << vis[g];
    return 0;
}