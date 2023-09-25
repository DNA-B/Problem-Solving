#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, M;
int arr[1001][1001];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
pair<int, int> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int cur = pow(N, 2);
    int dir = 0; // (dx, dy) index
    int nx = 1;
    int ny = 1;

    while (cur != 0)
    {   
        arr[nx][ny] = cur;
        cur--;
        
        if (nx + dx[dir] < 1 || nx + dx[dir] > N || ny + dy[dir] < 1 || ny + dy[dir]> N)
            dir = (dir + 1) % 4; // 다음 좌표가 경계를 벗어나는 경우 방향 전환
        if (arr[nx + dx[dir]][ny + dy[dir]] != 0) // 다음 좌표에 이미 값이 있는 경우 방향 전환
            dir = (dir + 1) % 4;

        nx += dx[dir];
        ny += dy[dir];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] == M)
            {
                ans.first = i;
                ans.second = j;
            }

            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    cout << ans.first << " " << ans.second;

    return 0;
}
