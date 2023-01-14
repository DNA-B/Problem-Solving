#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;
    vector<long long> res;

    cin >> n;

    res.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> str;

        string tmp = "";

        for (int j = str.length() - 1; j >= 0; j--)
        {
            while ((tmp == "") && (str[j] - '0' == 0))
                j--;

            tmp += str[j];
        }
        res[i] = stoll(tmp);
    }

    sort(res.begin(), res.end());

    for (long long item : res)
        cout << item << "\n";

    return 0;
}