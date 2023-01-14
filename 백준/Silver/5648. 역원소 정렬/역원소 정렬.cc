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

        reverse(str.begin(), str.end());
        res[i] = stoll(str);
    }

    sort(res.begin(), res.end());

    for (long long item : res)
        cout << item << "\n";

    return 0;
}