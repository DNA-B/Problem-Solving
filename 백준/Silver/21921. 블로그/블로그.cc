#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int arr[250001];
int N, X;
int ans = 0, cnt = 1, sum = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> X;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < X; i++) // 첫 window
        sum += arr[i];

    ans = sum;

    for (int i = X; i < N; i++) // 두 번째 윈도우부터 시작
    {
        sum += arr[i] - arr[i - X]; // 전 window의 맨 앞은 빼고, 현 window의 맨 끝 더하기

        if (sum >= ans)
        {
            if (sum == ans) // 기간 증가
                cnt++;
            else // 최대 방문자수 갱신
            {
                ans = sum;
                cnt = 1;
            }
        }
    }

    if (ans == 0)
        cout << "SAD";
    else
        cout << ans << "\n" << cnt;

    return 0;
}