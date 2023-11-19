#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string N, ans;
int L;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 1; i < L; i++)
        ans += "1";

    ans += N;
    cout << ans;

    return 0;
}
