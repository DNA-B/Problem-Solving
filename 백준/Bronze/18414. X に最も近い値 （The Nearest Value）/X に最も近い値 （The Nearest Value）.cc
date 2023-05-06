#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X, L, R;
    int min = 1000000000, min_val;
    
    cin >> X >> L >> R;

    for (int i = L; i <= R; i++)
    {
        if (abs(X - i) < min)
        {
            min = abs(X - i);
            min_val = i;
        }
    }

    cout << min_val;

    return 0;
}