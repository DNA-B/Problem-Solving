#include<bits/stdc++.h>

using namespace std;

int M, N; // M은 변의 길이, N은 명령어 개수
string order;
int order_n;
int x = 0, y = 0;
bool flag = false;
char cur_dir = 'E';

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    while (N--)
    {
        cin >> order;

        if (order == "MOVE")
        {
            cin >> order_n;

            switch (cur_dir)
            {
            case 'E':
                if (y + order_n > M)
                    flag = true;
                else
                    y += order_n;
                break;
            case 'W':
                if (y - order_n < 0)
                    flag = true;
                else
                    y -= order_n;
                break;
            case 'S':
                if (x - order_n < 0)
                    flag = true;
                else
                    x -= order_n;
                break;
            case 'N':
                if (x + order_n > M)
                    flag = true;
                else
                    x += order_n;
                break;
            }
        }
        else if (order == "TURN")
        {
            cin >> order_n;

            if (order_n == 0)
            {
                switch (cur_dir)
                {
                case 'E':
                    cur_dir = 'N';
                    break;
                case 'W':
                    cur_dir = 'S';
                    break;
                case 'S':
                    cur_dir = 'E';
                    break;
                case 'N':
                    cur_dir = 'W';
                    break;
                }
            }
            else
            {
                switch (cur_dir)
                {
                case 'E':
                    cur_dir = 'S';
                    break;
                case 'W':
                    cur_dir = 'N';
                    break;
                case 'S':
                    cur_dir = 'W';
                    break;
                case 'N':
                    cur_dir = 'E';
                    break;
                }
            }
        }
    }

    if (flag)
        cout << -1;
    else
        cout << y << " " << x;

    return 0;
}