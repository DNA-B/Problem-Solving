#include <bits/stdc++.h>

using namespace std;

int board[100001] = { 0 };
int dist[100001] = { 0 }; // 방문 + 초
int n, m; // n = 행, m = 열
int dx[3] = { -1, 1, 0 }; // 좌,우
// int dy[4] = { 0,0,-1,1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;
    int su, sis;
    
    cin >> su >> sis;

    fill(dist, dist + 100001, -1);
    q.push(su);
    dist[su] = 0;

    while (dist[sis] == -1) // 동생이 -1이 아니면 도착한 것
    {
        int cur = q.front();
        q.pop();
        dx[2] = cur;

        for (int dir = 0; dir < 3; dir++)
        { // -1, +1, *2;
            int x = cur + dx[dir]; // 방향 설정
            if (x < 0 || x > 100000) continue; // 범위 밖일 경우
            if (dist[x] != -1) continue; // 이미 방문

            dist[x] = dist[cur] + 1;
            q.push(x);
        }
    }

    cout << dist[sis];

    return 0;
}