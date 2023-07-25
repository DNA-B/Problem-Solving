#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
long long zero = 0, one = 0, etc = 0;
long long ans = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int x;
    while (N--)
    {
        cin >> x;

        if (x == 0)
            zero++;
        else if (x == 1)
            one++;
        else
            etc++;
    }

    ans += (zero * (zero - 1) / 2); // nC2 (n = 0)
    ans += (zero * etc); // (0, 2 이상)의 경우의 수
    ans += (zero * one) * 2; // (0, 1)의 경우의 수

    cout << ans;

    return 0;
}
