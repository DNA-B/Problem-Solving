#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    long long total = 0;
    long long yoon = 0;

    while (1)
    {
        cin >> yoon;
        
        if (yoon == -1)
            break;

        total += yoon;
    }

    cout << total;

    return 0;
}