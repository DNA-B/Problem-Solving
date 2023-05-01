#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
int arr[7][7];
int dx[3] = { 1, 1, 1 };
int dy[3] = { -1, 0, 1 };
int N, M;
int ans = INF;

int solve(int x, int y, int prev)
{
    if (x == N) // 달 도착
        return 0; 

    int val = INF;

    for (int dir = 0; dir < 3; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (prev == dir) // 이전 단계와 방향 일치
            continue;
        if (ny < 0 || ny >= M) 
            continue;

        val = min(val, solve(nx, ny, dir) + arr[x][y]);
    }

    return val;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    for (int i = 0; i < M; i++)
        ans = min(ans, solve(0, i, -1));

    cout << ans;

    return 0;
}