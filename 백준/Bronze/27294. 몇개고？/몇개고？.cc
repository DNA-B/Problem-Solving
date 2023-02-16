#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, s;

    cin >> t >> s;

    if ((s == 1) || (t < 12 || t > 16))
        cout << "280";
    else if((s == 0) && (t >= 12 && t <= 16))
        cout << "320";

    return 0;
}