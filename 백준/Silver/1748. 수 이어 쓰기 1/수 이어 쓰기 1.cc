#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
long long power = 1, ans = 9;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    
    if (N < 10)
        cout << N;
    else
    {
        power = to_string(N).length() - 1;
        
        for (int i = 1; i < power; i++)
            ans += (i + 1) * ((pow(10, i + 1) - 1) - pow(10, i) + 1);

        ans += (power + 1) * (N - pow(10, power) + 1);

        cout << ans;
    }


    return 0;
}