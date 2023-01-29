#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    int cur;
    vector <pair<int, int>> v;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        v.push_back({ i,x });
    }

    auto it = v.begin();

    while (!v.empty())
    {
        cur = it->second;

        cout << it->first << " ";

        it = v.erase(it);

        if (v.size() == 0)
            break;

        if (it == v.end())
            it = v.begin();

        if (cur < 0)
        {
            for (int i = cur; i < 0; i++)
            {
                if (it == v.begin())
                    it = v.end();

                it--; 
            }
        }
        else
        {
            for (int i = 0; i < cur - 1; i++)
            {
                if (it == v.end())
                    it = v.begin();

                it++;
            }
        }

        if (it == v.end())
            it = v.begin();
    }
    
    return 0;
}