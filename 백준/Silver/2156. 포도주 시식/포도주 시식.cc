#include <bits/stdc++.h>

using namespace std;

/* BOJ 2156 : 포도주 시식
- 계단 오르기와 비슷한 풀이
- 그러나 목적지에 도착하는 것이 목표가 아니기 때문에
- 마지막 잔을 무조건 마실 필요가 없다는 것이 주의점.
*/

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

    dp[1] = v[1];
    dp[2] = v[1] + v[2];

    for (int i = 3; i <= n; i++)
        dp[i] = max({ dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i], dp[i - 1]
            });
     
    cout << dp[n];

    return 0;
}