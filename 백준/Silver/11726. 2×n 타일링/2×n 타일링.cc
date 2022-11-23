#include <bits/stdc++.h>

using namespace std;

int dp[1001] = { 0 };

/*

BOJ 11726번 : 2xn 타일링
n = 1부터 n = 4까지 경우를 나눠 그려보면
n = 4일 때에 규칙을 발견할 수 있는데
n = 2일 때의 경우에 2*2를 추가한 것 2개와
n = 3일 때의 경우에 1*2를 추가한 것 3개가 더해져 5개가 나오게 된다.
즉 dp[n] = dp[n-1] + dp[n-2]와 같은 식으로 바꿀 수 있게 된다.

*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n];

    return 0;
}