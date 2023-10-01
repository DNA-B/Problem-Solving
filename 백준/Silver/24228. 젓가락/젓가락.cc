#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

long long N, R;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R;
    cout << (N + 1) + 2 * (R - 1);

    return 0;
}
