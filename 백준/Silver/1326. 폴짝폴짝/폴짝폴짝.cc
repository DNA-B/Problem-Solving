#include <bits/stdc++.h>

using namespace std;

int N, a, b;
int board[10001] = { 0 };
int dist[10001] = { 0 }; // 방문 + 초
queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> board[i];

    fill(dist, dist + 10001, -1);

    cin >> a >> b; // a == b, a > b, a < b

    if (a == b)
    {
        cout << 0;
        return 0;
    }

    dist[a] = 0;
    q.push(a);

    while (!q.empty()) // 동생이 -1이 아니면 도착한 것
    {
        int cur = q.front();
        q.pop();

        if (cur == b)
            break;

        for (int dir = cur + board[cur]; dir <= N; dir += board[cur])
        { // 배수 거리 전부 이동
            if (dist[dir] != -1)
                continue;

            dist[dir] = dist[cur] + 1;
            q.push(dir);
        }

        for (int dir = cur - board[cur]; dir >= 1; dir -= board[cur])
        { // 배수 거리 전부 이동
            if (dist[dir] != -1)
                continue;

            dist[dir] = dist[cur] + 1;
            q.push(dir);
        }

    }

    if (dist[b] == -1)
        cout << -1;
    else
        cout << dist[b];


    return 0;
}