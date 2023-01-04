#include <bits/stdc++.h>

using namespace std;

/* BOJ 2579 : 계단 오르기
- 경우 1: 1칸을 건너 뛸 때
- 경우 2 : 연속으로 2번 올랐을 때
- 목적지는 마지막 계단
*/

int dp[305];
vector<int> v(305);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    v.resize(n + 5);

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    dp[1] = v[1];
    dp[2] = v[1] + v[2];

    for (int i = 3; i <= n; i++)
        dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
     
    cout << dp[n];

    return 0;
}