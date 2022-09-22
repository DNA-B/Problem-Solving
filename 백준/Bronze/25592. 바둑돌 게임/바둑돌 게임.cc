#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int doll = 0;
    int take_n = 1;
    int result = 0;
    
    cin >> doll;

    while (1)
    {
        doll -= take_n;

        if (doll < 0)
        {
            if (take_n % 2 == 0)
            {
                cout << 0;
                return 0;
            }
            else
            {
                cout << abs(doll);
                return 0;
            }
        }
        take_n++;
    }

    return 0;
}