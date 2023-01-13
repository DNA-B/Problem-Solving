#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b)
{
    if (a.length() == b.length())
    {
        int sum_a = 0, sum_b = 0;

        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] - '0' >= 0 && a[i] - '0' <= 9)
                sum_a += a[i] - '0';

            if (b[i] - '0' >= 0 && b[i] - '0' <= 9)
                sum_b += b[i] - '0';
        }

        if (sum_a == sum_b)
            return a < b;
        else
            return sum_a < sum_b;
    }
    else
        return a.length() < b.length();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    vector<string> v;

    cin >> t;
    v.resize(t);

    for (int i = 0; i < t; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), cmp);

    for (auto item : v)
        cout << item << "\n";

    return 0;
}