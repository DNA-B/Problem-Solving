#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, K;
int ans = 0;
int soinsu[100001];

void era(int N)
{
    for (int i = 2; i <= N; i++)
    {
        if (soinsu[i])
            continue;

        for (int j = i; j <= N; j += i)
            soinsu[j] = max(soinsu[j], i); // 소수라면 배수의 소인수 최대값을 자신으로로 변경;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    era(N);

    for (int i = 1; i <= N; i++)
    {
        if (soinsu[i] <= K)
            ans++;
    }

    cout << ans;


    return 0;
}