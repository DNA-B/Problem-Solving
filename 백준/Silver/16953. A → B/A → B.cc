#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string A, B;
int ans = INF;

void AtoB(string s, int cur)
{
    if (s == B)
        ans = min(ans, cur);

    if (stoll(s) > stoll(B))
        return;

    AtoB(to_string(stoll(s) * 2), cur + 1);
    AtoB(s + '1', cur + 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    AtoB(A, 1);

    if (ans == INF)
        cout << -1;
    else
        cout << ans;

    return 0;
}