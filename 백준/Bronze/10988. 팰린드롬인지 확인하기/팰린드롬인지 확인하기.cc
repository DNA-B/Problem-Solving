#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    string re_str;

    cin >> str;

    re_str = str;
    reverse(re_str.begin(), re_str.end());

    if (str == re_str)
        cout << 1;
    else
        cout << 0;

    return 0;
}