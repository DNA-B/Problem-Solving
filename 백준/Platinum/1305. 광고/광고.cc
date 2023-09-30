#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int L;
string s;

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

    cin >> L >> s;

    vector<int> f = failure(s);

    cout << s.length() - f[s.length() - 1];


    return 0;
}
