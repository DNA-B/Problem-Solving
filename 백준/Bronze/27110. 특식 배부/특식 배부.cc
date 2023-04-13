#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int a, b, c;
    int ans = 0;

    cin >> N;
    cin >> a >> b >> c;

    ans += N < a ? N : a;
    ans += N < b ? N : b;
    ans += N < c ? N : c;

    cout << ans;

    return 0;
}