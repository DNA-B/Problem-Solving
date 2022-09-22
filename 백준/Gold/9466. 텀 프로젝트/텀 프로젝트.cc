#include <bits/stdc++.h>

using namespace std;

int board[100001];
int vis[100001];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test = 0;
    int count = 0;

    cin >> test;

    while (test--)
    {
        cin >> n;

        fill(vis + 1, vis + n + 1, 0);

        for (int i = 1; i <= n; i++) // 입력 + 혼자 팀 미리 처리
        {
            cin >> board[i];
            if (board[i] == i)
            {
                vis[i] = -1;
            }
        }

        for (int i = 1; i <= n; i++) // 조 편성
        {
            if (vis[i] != 0)
                continue;

            auto cur = i;
            while (1)
            {
                vis[cur] = i; // 지나갈 때마다 i로 바꿔서 cycle 확인
                cur = board[cur];

                if (vis[cur] == i) // 한 cycle을 -1로 체크
                {
                    while (vis[cur] != -1)
                    {
                        vis[cur] = -1;
                        cur = board[cur];
                    }
                    break;
                }

                if (vis[cur] != 0) // 한 바퀴를 돌았는데 i가 안나온다면 cycle이 아님
                {
                    break;
                }
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (vis[i] != -1)
                count++;
        }

        cout << count << "\n";
        count = 0;
    }
    return 0;
}