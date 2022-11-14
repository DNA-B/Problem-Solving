#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int res = 0;
   
    cin >> n;

    vector<int> v(n);
    vector<int> cur_time(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {    
        for (int j = 0; j <= i; j++)
        {
            cur_time[i] += v[j];
        }
        res += cur_time[i];
    }

    cout << res;

    return 0;
}