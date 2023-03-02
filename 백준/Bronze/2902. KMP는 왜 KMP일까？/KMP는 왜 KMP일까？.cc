#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    string ans = "";

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]))
            ans += str[i];
    }

    cout << ans;

    return 0;
}