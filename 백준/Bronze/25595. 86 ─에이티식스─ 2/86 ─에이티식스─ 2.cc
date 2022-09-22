#include <bits/stdc++.h>

using namespace std;

int main()
{ // 체스판으로 생각한다면 노우젠과 다른 색에 있는 레기온은 처치가 가능함.
    ios::sync_with_stdio(0);
    cin.tie(0);

    int board[100][100];
    int nozen;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 2)
            {
                if ((i + j) % 2 == 0)
                {
                    nozen = 0;
                }
                else
                {
                    nozen = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (board[i][j] == 1)
            {
                if (nozen == 0)
                {
                    if ((i + j) % 2 == 0)
                    {
                        cout << "Kiriya";
                        return 0;
                    }
                }
                else if (nozen == 1)
                {
                    if ((i + j) % 2 != 0)
                    {
                        cout << "Kiriya";
                        return 0;
                    }
                }
            }
        }
    }
     
    cout << "Lena";

    return 0;
}