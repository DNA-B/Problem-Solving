#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int ans = 0;
    vector<int> v(100000);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.begin() + n);

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, v[n - i] * i);
    }

    cout << ans;

    return 0;
}