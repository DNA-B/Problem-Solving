#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
bool has_odd = false;
map<char, int> m;
char mid_char;
string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> s;

    for (int i = 0; i < s.length(); i++)
    {
        if ((N % 2 != 0) && (i == N / 2))
        {
            mid_char = s[i];
            continue;
        }

        m[s[i]]++;
    }

    for (auto item : m)
    {
        if (item.second % 2 != 0)
        {
            if ((item.second == 1) && (item.first == mid_char))
                has_odd = false;
            else
                has_odd = true;
        }
    }

    if (has_odd)
        cout << "No";
    else
        cout << "Yes";

    return 0;
}