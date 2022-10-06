#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d,h,m;
    int ans, pivot;
    
    cin >> d >> h >> m;
    
    pivot = 11 + 11 * 60 + 11 * 60 * 24;
    ans = m + h * 60 + d * 60 * 24 - pivot;
    
    if(ans < 0 ) 
    {
        cout << -1 <<'\n';
    }
    else
    {
        cout << ans <<'\n';
    }
    return 0;
}