#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string s;
set<string> subs;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        string tmp = "";
        for (int j = i; j < s.length(); j++)
        {
            tmp.push_back(s[j]);
            subs.insert(tmp);
        }
    }

    cout << subs.size();

    return 0;
}
