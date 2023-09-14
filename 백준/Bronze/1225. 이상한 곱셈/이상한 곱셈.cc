#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string A, B;
long long ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    for (auto itemA : A)
        for (auto itemB : B)
            ans += (long long)(itemA - '0') * (itemB - '0');

    cout << ans;

    return 0;
}
