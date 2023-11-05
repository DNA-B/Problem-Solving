#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string s, ans, tmp;
int cnt_odd = 0;
char odd_char;
map<char, int> m;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for (int i = 0; i < s.length(); i++)
        m[s[i]]++;

    for (auto item : m)
    {
        if (item.second % 2 != 0)
        {
            cnt_odd++;
            odd_char = item.first;

            if (cnt_odd > 1)
            {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }

        for (int i = 0; i < item.second / 2; i++)
            ans += item.first;
    }

    tmp = ans;
    reverse(tmp.begin(), tmp.end());

    if (cnt_odd == 1)
        ans += odd_char + tmp;
    else
        ans += tmp;

    cout << ans;

    return 0;
}