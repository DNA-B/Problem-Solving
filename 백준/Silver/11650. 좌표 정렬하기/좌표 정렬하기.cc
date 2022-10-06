#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first) return p1.second < p2.second;
    else return p1.first < p2.first;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> v;
    int x, y;
    int rep;

    cin >> rep;

    while (rep--)
    {
        cin >> x >> y;
        v.push_back({ x,y });
    }

    stable_sort(v.begin(), v.end(), compare);

    for (auto item : v)
    {
        cout << item.first << " " << item.second << "\n";
    }

    return 0;
}