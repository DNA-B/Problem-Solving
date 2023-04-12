#include<bits/stdc++.h>

using namespace std;

int ca, ba, pa;
int cr, br, pr;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> ca >> ba >> pa;
    cin >> cr >> br >> pr;

    ans += ca < cr ? cr - ca : 0;
    ans += ba < br ? br - ba : 0;
    ans += pa < pr ? pr - pa : 0;
    
    cout << ans;

    return 0;
}