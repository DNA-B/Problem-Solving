#include<bits/stdc++.h>

using namespace std;

string A, B, C, D;
string AB, CD;
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C >> D;
    
    AB = A + B;
    CD = C + D;
    ans = stoll(AB) + stoll(CD);
    cout << ans;

    return 0;
}