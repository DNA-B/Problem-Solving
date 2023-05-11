#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, k = 0, ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (1) 
    {
        k++;
        
        if (N == 0) 
            break;
        
        if (N < k)
            k = 1;

        N -= k;

        ans++;
    }

    cout << ans;

    return 0;
}