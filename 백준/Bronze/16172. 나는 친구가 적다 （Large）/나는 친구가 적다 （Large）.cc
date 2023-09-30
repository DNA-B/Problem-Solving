#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int cnt = 0;
vector<int> idx;

vector<int> failure(string& s)
{
    vector<int> f(s.length());

    int j = 0;

    for (int i = 1; i < s.length(); i++)
    {
        while (j > 0 && s[i] != s[j])
            j = f[j - 1];

        if (s[i] == s[j])
            f[i] = ++j;
    }

    return f;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    string p;

    cin >> s;
    cin >> p;

    vector<int> f = failure(p);
    int j = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            continue;

        while (j > 0 && s[i] != p[j])
            j = f[j - 1];

        if (s[i] == p[j])
            j++;

        if (j == p.length())
        {
            cout << 1;
            return 0;
        }
    }

    cout << 0;

    return 0;
}
