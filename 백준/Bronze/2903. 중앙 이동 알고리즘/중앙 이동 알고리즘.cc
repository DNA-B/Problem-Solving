#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    ans = pow(pow(2, N) + 1, 2);
    cout << ans;

    return 0;
}
