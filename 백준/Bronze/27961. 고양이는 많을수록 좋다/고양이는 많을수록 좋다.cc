#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

long long N;
long long ans = 1;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    if (N == 0)
    {
        cout << 0;
        return 0;
    }

    long long tmp = 1;
    while (tmp < N)
    {
        tmp *= 2;
        ans++;
    }

    cout << ans;

    return 0;
}