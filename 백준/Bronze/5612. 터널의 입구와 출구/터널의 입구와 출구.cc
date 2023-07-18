#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, M;
int st, en;
int ans = -1;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    ans = max(ans, M);
    for (int i = 0; i < N; i++)
    {

        cin >> st >> en;

        M += (st - en);
        ans = max(ans, M);

        if (M < 0)
        {
            cout << 0;
            return 0;
        }
    }

    cout << ans;

    return 0;
}