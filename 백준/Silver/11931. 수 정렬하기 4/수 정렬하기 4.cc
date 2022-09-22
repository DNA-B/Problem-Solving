#include <bits/stdc++.h>

using namespace std;

bool compare(int x, int y)
{
    return x > y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int rep;
    int x;

    cin >> rep;

    while (rep--)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), compare);

    for (int item : v)
    {
        cout << item << "\n";
    }

    return 0;
}