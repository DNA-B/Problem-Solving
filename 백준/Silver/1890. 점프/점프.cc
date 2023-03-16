#include <bits/stdc++.h>

using namespace std;

int N;
int board[101][101];
long long mem[101][101];
int nx, ny;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
 
    mem[0][0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            nx = i + board[i][j];
            ny = j + board[i][j];

            if (mem[i][j] == 0) // {0, 0}에서 갈 수 없는 곳
                continue;
            if (i == N - 1 && j == N - 1) // 도착점
                continue;
            
            // if (||로 묶어버리면 둘 중 하나는 갈 수 있는데도 continue되기 떄문에 따로 작성)
            if(nx < N)
                mem[nx][j] = mem[nx][j] + mem[i][j];
            if(ny < N)
                mem[i][ny] = mem[i][ny] + mem[i][j]; 
        }
    }

    cout << mem[N - 1][N - 1];

    return 0;
}