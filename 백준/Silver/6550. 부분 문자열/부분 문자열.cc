#include <bits/stdc++.h>

using namespace std;

string s, t;
int cur = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> s >> t;

        if (cin.eof())
            break;

        if (s.length() > t.length())
        {
            cout << "No\n";
            continue;
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == s[cur])
                cur++;
        }

        if (cur == s.length())
            cout << "Yes\n";
        else
            cout << "No\n";

        cur = 0;
    }

    return 0;
}