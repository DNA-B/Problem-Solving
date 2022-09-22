#include <bits/stdc++.h>

using namespace std;

/*
- 쿼드트리랑 풀이법이 거의 같음.
- 사분면으로 나누는 (분할정복, 재귀) 알고리즘.
*/

int confetti[128][128];
int b = 0;
int w = 0;

void q_tree(int n, int r, int c)
{
    if (n == 1) // base condition
    {
        if (confetti[r][c] == 1)
            b++;
        else
            w++;

        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (confetti[r + i][c + j] != confetti[r][c])
            { /* 첫 색을 기준으로 다른 색이 나올 경우 
              (n / 2) 크기의 4사분면으로 분할한다. */
                q_tree(n / 2, r, c); // 1사분면
                q_tree(n / 2, r, c + (n / 2)); // 2사분면
                q_tree(n / 2, r + (n / 2), c); // 3사분면
                q_tree(n / 2, r + (n / 2), c + (n / 2)); // 4사분면
                return;
            }
        }
    }
    
    // 반복문에서 나왔으므로 현재 칸은 하나의 색이다.
    if (confetti[r][c] == 1)
        b++;
    else
        w++;

    return;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> confetti[i][j];
        }
    }

    q_tree(n, 0, 0);

    cout << w << "\n" << b;

    return 0;
}