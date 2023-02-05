#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    map<int, int> x;
    map<int, int> y;
    int xx, yy;

    for (int i = 0; i < 3; i++)
    {
        cin >> xx >> yy;
        x[xx]++;
        y[yy]++;
    }

    for (auto item : x)
        if (item.second == 1)
            cout << item.first << " ";

    for (auto item : y)
        if (item.second == 1)
            cout << item.first;

    return 0;
}