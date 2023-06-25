#include<bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int B;
string N;
int ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> B;

    for (int i = 0, j = N.length() - 1; i < N.length(); i++, j--)
    {
        if ('0' <= N[i] && N[i] <= '9')
            ans += (N[i] - '0') * (pow(B, j));
        else
            ans += (10 + (N[i] - 'A')) * (pow(B, j));
    }

    cout << ans;

    return 0;
}