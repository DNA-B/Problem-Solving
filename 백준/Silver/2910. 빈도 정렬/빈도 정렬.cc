#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second > b.second;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, int>> v;
    int n, bound;
    int x;

    cin >> n >> bound;

    for (int i = 0; i < n; i++)
    {
        bool is_none = true;
        cin >> x;

        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].first == x)
            {
                v[j].second++;
                is_none = false;
                break;
            }
        }
        
        if (is_none)
            v.push_back({ x, 1 });
    }

    stable_sort(v.begin(), v.end(), cmp);

    for (auto item : v)
    {
        while(item.second--)
            cout << item.first << " ";
    }

    return 0;
}