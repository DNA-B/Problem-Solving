#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int a, b, c;

    cin >> a >> b >> c;

    ans = a + b + c;
    ans -= max({ a, b, c }) + min({ a, b, c });

    cout << ans;

    return 0;
}