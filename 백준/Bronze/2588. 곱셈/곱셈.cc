#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    string y_str;

    cin >> x >> y;

    y_str = to_string(y);

    for (int i = y_str.length() - 1; i >= 0; i--)
        cout << x * (y_str[i] - '0') << "\n";

    cout << x * y;
    return 0;
}