#include <bits/stdc++.h>

using namespace std;

int N, K;
int cnt = 0;
int res = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
            cnt++;

        if (cnt == K)
        {
            res = i;
            break;
        }
    }

    if (res == 0)
        cout << 0;
    else
        cout << res;

    return 0;
}