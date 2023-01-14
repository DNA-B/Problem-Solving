#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int n, m;
    int cur_min_idx = -1;
    int res = 0;
    vector<int> a;
    vector<int> b;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        a.resize(n);
        b.resize(m);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0; i < n; i++)
        {
            for (int j = cur_min_idx + 1; j < m; j++)
            {
                if (a[i] <= b[j])
                    break;
                else
                    cur_min_idx = j;
            }
            res += cur_min_idx + 1;
        }

        cout << res << "\n";

        res = 0;
        cur_min_idx = -1;
    }
    
    return 0;
}