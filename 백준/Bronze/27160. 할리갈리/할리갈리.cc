#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> m;
    string str;
    int num_fruits;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str >> num_fruits;
        m[str] += num_fruits;
    }

    for (auto item : m)
    {
        if (item.second == 5)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}