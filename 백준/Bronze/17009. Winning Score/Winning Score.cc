#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    int a = 0;
    int b = 0;
    int cnt = 3;

    while (cnt--)
    {
        cin >> x;
        
        if (cnt == 3)
            a += x * 3;
        else if (cnt == 2)
            a += x * 2;
        else
            a += x;
    }
    
    cnt = 3;

    while (cnt--)
    {
        cin >> x;

        if (cnt == 3)
            b += x * 3;
        else if (cnt == 2)
            b += x * 2;
        else
            b += x;
    }

    if (a == b)
        cout << 'T';
    else if (a > b)
        cout << "A";
    else
        cout << "B";

        return 0;
}