#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int button_A = 0;
    int button_B = 0;
    int button_C = 0;

    int time;

    cin >> time;

    if (time % 10 != 0)
    {
        cout << -1;
    }   
    else
    {
        if (time / 300 != 0)
        {
            button_A += (time / 300);
            time -= 300 * (time / 300);
        }

        if (time / 60 != 0)
        {
            button_B += (time / 60);
            time -= 60 * (time / 60);
        }
        if (time / 10 != 0)
        {
            button_C += (time / 10);
            time -= 10 * (time / 10);
        }
        cout << button_A << " " << button_B << " " << button_C;
    }
    
    return 0;
}