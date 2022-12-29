#include <bits/stdc++.h>

using namespace std;

string str;

bool compare(string a, string b)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (isupper(a[i]))
            a[i] += 32;
    }

    for (int i = 0; i < b.length(); i++)
    {
        if (isupper(b[i]))
            b[i] += 32;
    }

    return a < b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (true)
    {
        int n;
        vector<string> v;

        cin >> n;

        if (n == 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            cin >> str;
            v.push_back(str);
        }

        sort(v.begin(), v.end(), compare);

        cout << v[0] << "\n";
    }

    return 0;
}