#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, ans = 0;
int plug;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> plug;
        ans += plug;
    }

    ans -= (N - 1);
    cout << ans;

    return 0;
}