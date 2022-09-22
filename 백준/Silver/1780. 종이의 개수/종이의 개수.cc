#include <bits/stdc++.h>

using namespace std;

/*
- 색종이 만들기랑 똑같음
- 그냥 4칸으로 나누던거에서 9칸으로 바뀜.
*/

int confetti[2187][2187];
int m_one = 0;
int zero = 0;
int one = 0;

void q_tree(int n, int r, int c)
{
    if (n == 1) // base condition
    {
        if (confetti[r][c] == 1)
            one++;
        else if (confetti[r][c] == 0)
            zero++;
        else
            m_one++;

        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (confetti[r + i][c + j] != confetti[r][c])
            { /* 첫 색을 기준으로 다른 색이 나올 경우 
              (n / 3) 크기의 9구역으로 분할한다. */
                q_tree(n / 3, r, c); // 1-1
                q_tree(n / 3, r, c + (n / 3)); // 1-2
                q_tree(n / 3, r, c + (n / 3) * 2); // 1-3
                
                q_tree(n / 3, r + (n / 3), c); // 2-1
                q_tree(n / 3, r + (n / 3), c + (n / 3)); // 2-2
                q_tree(n / 3, r + (n / 3), c + (n / 3) * 2); // 2-3

                q_tree(n / 3, r + (n / 3) * 2, c); // 3-1
                q_tree(n / 3, r + (n / 3) * 2, c + (n / 3)); // 3-2
                q_tree(n / 3, r + (n / 3) * 2, c + (n / 3) * 2); // 3-3
                return;
            }
        }
    }
    
    // 반복문에서 나왔으므로 현재 칸은 하나의 색이다.
    if (confetti[r][c] == 1)
        one++;
    else if (confetti[r][c] == 0)
        zero++;
    else
        m_one++;

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

    cout << m_one << "\n" << zero << "\n" << one;

    return 0;
}