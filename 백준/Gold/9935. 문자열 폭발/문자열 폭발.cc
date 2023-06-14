#include<bits/stdc++.h>
#include<regex>

#define INF 0x3f3f3f3f

using namespace std;

string str, boom, ans = "";
int boom_len, pos;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str >> boom;

    for (int i = 0; i < str.length(); i++)
    {
        ans += str[i];

        if (ans.length() >= boom.length() && str[i] == boom[boom.length() - 1])
        {
            if (ans.substr(ans.length() - boom.length(), boom.length()) == boom)
            {
                for (int j = 0; j < boom.length(); j++)
                    ans.pop_back();
            }
        }
    }

    if (ans.size() == 0)
        cout << "FRULA";
    else
        cout << ans;

    return 0;
}