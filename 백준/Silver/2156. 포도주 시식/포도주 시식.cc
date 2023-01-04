#include <bits/stdc++.h>

using namespace std;

int dp[10005];
vector<int> v(10005);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, res = -1;

    cin >> n;
    v.resize(n + 5);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

   

    for (int j = 1; j <= n; j++)
    {
        fill(dp, dp + 10005, 0);
        dp[j] = v[j];
        dp[j + 1] = v[j] + v[j + 1];

        for (int i = 3; i <= n; i++)
            dp[i] = max({dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i], dp[i - 1]
    });

        for (int i = 1; i <= n; i++)
        {
            if (dp[i] > res)
                res = dp[i];
        }
    }
     
    cout << res;

    return 0;
}