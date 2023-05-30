#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
char board[1001][1001];
int heart_x, heart_y;
int la, ra, w, ll, rl;

int find_body(int nx, int ny, string body)
{
    int cnt = 0;

    while (1)
    {
        if (nx < 1 || nx > N || ny < 1 || ny > N)
            break;
        if (board[nx][ny] == '_')
            break;

        cnt++;
        
        if (body == "la")
            ny--;
        else if (body == "ra")
            ny++;
        else if (body == "w")
            nx++;
        else if (body == "ll")
            nx++;
        else if (body == "rl")
            nx++;
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
             
    for (int i = 1; i <= N; i++) // 심장 찾기
    {
        for (int j = 1; j <= N; j++) 
        {
            if (i - 1 < 1 || i + 1 > N)
                continue;
            if (j - 1 < 1 || j + 1 > N)
                continue;

            if (board[i][j] == '*') 
            {
                if (board[i][j - 1] != '*')
                    continue;
                if (board[i][j + 1] != '*')
                    continue;
                if (board[i + 1][j] != '*')
                    continue;
                if (board[i + 1][j] != '*')
                    continue;
                
                heart_x = i; // 심장 발견
                heart_y = j;
                break;
            }
        }
    }

    la = find_body(heart_x, heart_y - 1, "la");
    ra = find_body(heart_x, heart_y + 1, "ra");
    w = find_body(heart_x + 1, heart_y, "w");
    ll = find_body(heart_x + (w + 1), heart_y - 1, "ll");
    rl = find_body(heart_x + (w + 1), heart_y + 1, "rl");
   
    cout << heart_x << " " << heart_y << "\n";
    cout << la << " " << ra << " " << w << " " << ll << " " << rl << "\n";

    return 0;
}