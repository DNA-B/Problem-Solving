#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int level;

    cin >> level;

    if (200 <= level && level < 206)
        cout << 1;
    else if (206 <= level && level < 218)
        cout << 2;
    else if (218 <= level && level < 229)
        cout << 3;
    else
        cout << 4;

    return 0;
}