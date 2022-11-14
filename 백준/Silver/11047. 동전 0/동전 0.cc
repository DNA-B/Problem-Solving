#include <bits/stdc++.h>

using namespace std;

vector<int> v(11);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int k = 0;
    int cur = 0;
    int cnt = 0;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {    
        if (v[i] <= k)
        {
            cnt += k / v[i];
            k -= v[i] * (k / v[i]);
        }
    }

    cout << cnt;
    return 0;
}