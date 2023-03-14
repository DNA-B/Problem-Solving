#include <bits/stdc++.h>

using namespace std;

int R, C, N;
int cnt = 0;
char board[201][201];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

void print_arr()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> N;

    for (int i = 0; i < R; i++) // 1단계
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'O')
                q.push({ i,j });              
        }
    }

    cnt++; // 2단계

    while (cnt != N)
    {
        for (int i = 0; i < R; i++) // 3단계   
            fill(board[i], board[i] + 201, 'O');

        if (cnt + 1 != N)
            cnt++;
        else
            break;

        // 4단계
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop(); 
/*
            여기서 주의할 점은 queue에 들어있는 폭탄은 모두 동시에 터진다고 가정해야 한다.
            그래서 이미 전 bfs에서 터졌더라도 아직 남아있다 가정하고 이것또한 터트려주어야 동시에 터지는 효과가 나온다.
*/
            board[cur.first][cur.second] = '.';

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                    continue;
                if (board[nx][ny] == '.')
                    continue;

                board[nx][ny] = '.';
            }
        }

        if (cnt + 1 != N)
            cnt++;
        else
            break;

        // 4단계 끝 -> queue setting
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (board[i][j] == 'O')
                    q.push({ i, j });
            }
        }
    }
        
    print_arr();
    
    return 0;
}