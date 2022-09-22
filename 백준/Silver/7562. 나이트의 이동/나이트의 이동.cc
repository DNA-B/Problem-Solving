#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;


//int board[301][301];
int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 }; // 나이트 이동 가능
int dy[8] = { -2, -1, 1 ,2, 2, 1, -1, -2 };

int main() 
{
    IO;

    int rep;
    int l;
    int x, y;
    int wx, wy;

    cin >> rep;

    while (rep--)
    {
        queue<pair<int, int>> q;
        int vis[301][301] = { {0} };

        cin >> l;
        cin >> x >> y;
        cin >> wx >> wy;

        q.push({ x,y });

        while (!q.empty()) // BFS
        {
            auto cur = q.front();
            q.pop();

            if (cur.first == wx && cur.second == wy) // 좌표 같으면 발견(큐는 최소값 순서)
            {
                cout << vis[wx][wy] << "\n";
                break;
            }

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.first + dx[dir]; // 방향 설정
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= l || ny >= l || ny < 0) continue; // 범위 밖일 경우
                if (vis[nx][ny] != 0) continue; // 이미 방문

                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                q.push({ nx,ny });
            }
        }
    }

    return 0;
}