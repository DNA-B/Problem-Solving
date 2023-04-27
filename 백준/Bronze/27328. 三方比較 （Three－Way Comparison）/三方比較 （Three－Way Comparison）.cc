#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;

    cin >> a >> b;

    if (a < b)
        cout << -1;
    else if (a == b)
        cout << 0;
    else
        cout << 1;

    return 0;
}