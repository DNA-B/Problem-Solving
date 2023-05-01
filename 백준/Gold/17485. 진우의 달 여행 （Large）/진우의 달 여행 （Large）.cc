#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int arr[1001][1001];
int mem[1001][1001][4];
int dy[3] = { -1, 0, 1 };
int N, M;
int ans = INF;

int solve(int x, int y, int prev)
{
    if (x == N)
        return arr[x][y];

    if (mem[x][y][prev] != INF)
        return mem[x][y][prev];

    for (int dir = 0; dir < 3; dir++)
    {
        int nx = x + 1;
        int ny = y + dy[dir];

        if (nx > N || ny < 1 || ny > M)
            continue;
        if (dir == prev)
            continue;

        mem[x][y][prev] = min(mem[x][y][prev], solve(x + 1, y + dy[dir], dir) + arr[x][y]);
    }

    return mem[x][y][prev];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> arr[i][j];

    fill(&mem[0][0][0], &mem[1000][1000][3], INF);

    for (int i = 1; i <= M; i++)
        ans = min(ans, solve(0, i, -1));

    cout << ans;

    return 0;
}