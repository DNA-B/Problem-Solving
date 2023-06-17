#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int HH, MM;
int st, en;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> HH >> MM;

    st = 9 * 60;
    en = HH * 60 + MM;

    ans = en - st;

    cout << ans << "\n";

    return 0;
}